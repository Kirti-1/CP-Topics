/*
Sum Of Digits (Recursive)
Problem statement
Write a recursive function that returns the sum of the digits of a given integer.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9

*/
int sumOfDigits(int n) {
    // Write your code here
    if(n < 10){
        return n;
    }
    return n%10 + sumOfDigits(n/10);
}


