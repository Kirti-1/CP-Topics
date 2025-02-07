/*
Longest Consecutive Sequence
Problem statement
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Explanation:The longest consecutive sequence here is [8, 9, 10, 11, 12]. So the output is the start and end of this sequence: [8, 12].
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation:There are two sequences of equal length here: [1,2,3] and [7,8,9]. But since [7,8,9] appears first in the array (7 comes before 1), we return this sequence. So the output is [7,9].
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
Explanation:The longest consecutive sequence here is [15,16]. So the output is [15,16].

*/

#include <unordered_set>
#include <vector>
#include <unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
     unordered_set<int> elements;
    unordered_map<int, int> indexMap;

    // Populate the set and map
    for (int i = 0; i < n; i++) {
        elements.insert(arr[i]);
        indexMap[arr[i]] = i; // Map each number to its index for tie-breaking
    }

    int maxLength = 0;
    int startOfLongest = arr[0];

    for (int i = 0; i < n; i++) {
        int num = arr[i];

        // If num is the start of a sequence
        if (elements.find(num - 1) == elements.end()) {
            int currentNum = num;
            int length = 0;

            // Count consecutive numbers
            while (elements.find(currentNum) != elements.end()) {
                currentNum++;
                length++;
            }

            // Update the longest sequence
            if (length > maxLength || 
                (length == maxLength && indexMap[num] < indexMap[startOfLongest])) {
                maxLength = length;
                startOfLongest = num;
            }
        }
    }

    // Construct the result
    vector<int> result;
    if (maxLength > 1) {
        result.push_back(startOfLongest);
        result.push_back(startOfLongest + maxLength - 1);
    } else {
        result.push_back(startOfLongest);
    }

    return result;

}