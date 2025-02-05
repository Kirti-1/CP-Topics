/*
String to Integer
Problem statement
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/
#include <cmath>
#include <cstring>
using namespace std;
int stringToInteger(char str[], int len) {
    if (len == 1) {
        return str[0] - '0'; // Convert the first character to an integer
    }
    // Recursive call with the next character and updated length
    return ((str[0] - '0') * pow(10, len - 1)) + stringToInteger(str + 1, len - 1);
}
int stringToNumber(char input[]) {

   int length = strlen(input);
    // Convert the string to an integer
    return stringToInteger(input, length);
}


