/*
Remove Duplicates
roblem statement
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
void removeConsecutiveDuplicates(char *input, char ch, int pindex){
	int length = strlen(input);

	// pindex is processing index of character array. and ch is the last character from character array
	if(input[pindex] == '\0'){
		return;
	}

	if(input[pindex] == ch){
		
		// If our character at processing index equals to the last character from character array that is passed.
		// displace the character by 1 towards left
		int i = pindex-1;
		while(i <= length){
			input[i]  = input[i+1];
			i++;
		}
		// the processing character would also decrease by 1 as the character array got shifted by 1 to the left.
		removeConsecutiveDuplicates(input, input[pindex-1], pindex);

	}else{
		removeConsecutiveDuplicates(input, input[pindex], pindex+1);
	}

}

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

	int len = strlen(input);
	if(len == 2 && input[0] == input[1]){
		input[1] = '\0';
	}
	if(strlen(input) > 1)
		removeConsecutiveDuplicates(input, input[0],1);
}