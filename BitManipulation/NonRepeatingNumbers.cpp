/*
Non Repeating Numbers
(GFG)
Given an array arr[] containing 2*n+2 positive numbers, out of which 2*n numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

Examples:

Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4] 
Explanation: 3 and 4 occur exactly once.
Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]
Explanation: 1 and 3 occur exactly once.
Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]
Explanation: 1 and 2 occur exactly once.
Constraints:
2 <= arr.size() <= 106 
1 <= arr[i] <= 5 * 106
arr.size() is even

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> singleNumber(vector<int>& arr) {
        // Code here.
        int xor_result = 0;
        for(int i=0;i<arr.size();i++){
            xor_result ^= arr[i];
        }
        //find the right most set bit
        int set_bit = xor_result & -xor_result;
        
        int x = 0, y = 0;
        for(int i:arr){
            //bit is set group
            if(i & set_bit){
                x ^= i;
            }else{
                //bit is not set group
                y ^= i;
            }
        }
        
        return (x > y) ? vector<int>{y,x} : vector<int>{x,y};
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNumber(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends