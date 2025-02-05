/*
Replace Pi
Problem statement
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50
*/
// Change in the given string itself. So no need to return or print anything

#include <iostream>
#include<cstring>
using namespace std;
void replacePi(char input[], int i) {
	// Write your code here
	if(input[i] == '\0'){
		return;
	}
	if(input[i] == 'p'){
		if(i+1 < strlen(input) && input[i +1] == 'i'){
			//main processing
			int len = strlen(input);
			int new_length = len + 2;
			input[new_length] = '\0';
			for (int j = len; j >= i + 2; j--) {
            	input[j + 2] = input[j];  // Move characters 2 positions to the right
        	}
			input[i] = '3';
			input[i+1] = '.';
			input[i+2] = '1';
			input[i+3] = '4';
			replacePi(input, i+4);


		}else{
			replacePi(input, i+1);
		}
	}else{
		replacePi(input, i+1);
	}
	



}
void replacePi(char input[]) {
	// Write your code here
	replacePi(input,0);
}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
