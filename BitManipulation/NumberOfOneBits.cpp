/**
Given a positive integer n. Your task is to return the count of set bits.

Examples:

Input: n = 6
Output: 2
Explanation: Binary representation is '110', so the count of the set bit is 2.
Input: n = 8
Output: 1
Explanation: Binary representation is '1000', so the count of the set bit is 1.
Input: n = 3
Output: 2
Constraints:
1 ≤ n ≤ 109


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int  c = 0;
        while(n > 0){
            // cout << (1 << b) << endl;
            if(n & 1){
                c++;
            }
            n = n>>1;
        }
        return c;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
