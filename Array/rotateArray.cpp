/*
Rotate Array
Problem statement
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

 Note:
Change in the input array/list itself.You don't need to return or print the elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

void rotate(int *input, int d, int n)
{
    //Write your code here
    for(int i=0,j=d-1;i<=j;i++,j--){
         int temp = input[i];
         input[i] = input[j];
         input[j] = temp;
    }
    for(int i=d,j=n-1;i<=j;i++,j--){
         int temp = input[i];
         input[i] = input[j];
         input[j] = temp;
    }
    for(int i=0,j=n-1;i<=j;i++,j--){
         int temp = input[i];
         input[i] = input[j];
         input[j] = temp;
    }
   
}