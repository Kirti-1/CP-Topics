/*
Pair Sum To Zero
Problem statement
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.



Note:
Array A can contain duplicate elements as well.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
Explanation
(2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2.

*/
#include<map>
int pairSum(int *arr, int n) {
	map<int, int> freq;

    // Count frequencies of elements
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int pairCount = 0;

    // Iterate through the map
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int key = it->first;
        int value = it->second;

        if (key == 0) {
            // Special case for zeros
            pairCount += (value * (value - 1)) / 2; // Combination of zero pairs
        } else if (freq.count(-key)) {
            // Count pairs for (key, -key)
            pairCount += value * freq[-key];
            freq[-key] = 0; // Mark -key as processed to avoid double-counting
        }

        it->second = 0; // Mark key as processed
    }

    return pairCount;

}