#include <string.h>
#include <stdio.h>
int main() {
	char nextChar = 'a';
	char alphabet1[27];
	for(int i = 0; i < 26; ++i) {
		alphabet1[i] = nextChar;
		++nextChar;
	}
	alphabet1[26] = '\0';
	char alphabet2[] = "abcdefghijklmnopqrstuvwxyz";
	printf("Both lowercase alphabet strings are the same: %d\n", strcmp(alphabet1, alphabet2) == 0);
	int lowerToUpper = 'A'-'a'; //This value will probably be -32
	for(int i = 0; i < 26; ++i) {
		alphabet1[i] += lowerToUpper;
	}
	printf("Both strings are same after modification: %d\n", strcmp(alphabet1, alphabet2) == 0);

	char bothAlphabets[56];
	strcpy(bothAlphabets, alphabet1);
	strcat(bothAlphabets, alphabet2);
	printf("Looped Upper: %s, Hardcoded Lower: %s, Concatenation: %s\n", alphabet1, alphabet2, bothAlphabets);

}
