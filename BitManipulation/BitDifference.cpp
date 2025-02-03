/*
Bit Difference
You are given two numbers a and b. The task is to count the number of bits needed to be flipped to convert a to b.

Examples:

Input: a = 10, b = 20
Output: 4
Explanation:
a  = 01010
b  = 10100
As we can see, the bits of A that need to be flipped are 01010. If we flip these bits, we get 10100, which is B.
Input: a = 20, b = 25
Output: 3
Explanation:
a  = 10100
b  = 11001
As we can see, the bits of A that need to be flipped are 10100. If we flip these bits, we get 11001, which is B.
Constraints: 
1 ≤ a, b ≤ 106

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){

        /*
        Basic Approach
        int c = 0;
        for(int i=0;i<32;i++){
            if((a & (1 << i)) != (b & (1 << i))){
                c++;
            }
           }
            return c;
        } 
        */

         // XOR the numbers to find differing bits
        int xorResult = a ^ b;
        
        // Count the number of 1's in the XOR result
        int count = 0;
        while (xorResult) {
            count += xorResult & 1;
            xorResult >>= 1;
        }
        
        return count;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends