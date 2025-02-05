/*
Sum Of array (Recursive)
Problem statement
Given an array of length N, you need to find and return the sum of all elements of the array.

Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
Sample Input 2 :
3
4 2 1
Sample Output 2 :
7    
*/
int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
  if(n == 1){
    return input[0];
  }
  return input[n-1] + sum(input, n-1);
}
