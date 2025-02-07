/*
Remove Duplicates
Problem statement
Given a string S, remove consecutive duplicates from it recursively.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include<cstring>
void removeConsecutiveDuplicates(char* input, char prevChar, int index, int &k){
	if(input[index]=='\0'){
		return;
	}
	if(prevChar == input[index]){
		removeConsecutiveDuplicates(input, prevChar, index+1,k);
	}else{
		input[k] = input[index];
			k++;
		
		removeConsecutiveDuplicates(input, input[index], index+1,k);
	}
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	
	if(input[0]=='\0'){
		return;
	}
	int k = 1;
	removeConsecutiveDuplicates(input, input[0], 1,k);

	input[k] = '\0';
  

}