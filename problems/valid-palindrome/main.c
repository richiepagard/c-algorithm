#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void isPalindrome(char *s);

int main() {
	isPalindrome("A man, a plan, a canal: Panama");

	return 0;
}


void removeSpaces(char *string) {
	int i = 0, j = 0;

	// Iterate through each character of the string
	while(string[i] != '\0')
	{
		// Copy non-space characters to the new position
		if(string[i] != ' ') string[j++] = string[i];
		i++;
	}

	// Null-terminate the resulting string
	string[j] = '\0';
}

int stringLength(char *string) {
	int counter = 0;

	// Count characters until the null-terminate is reached
	while(string[counter] != '\0') counter++;

	// Return the length of the string(excluding null-terminate)
	return counter;
}

void stringCopy(char *copied_str, char *main_str) {
	int i = 0;

	// Copy the characters one by one until the null-terminate
	while(main_str[i] != '\0') {
		copied_str[i] = main_str[i];
		i++;
	}
}

void isPalindrome(char *s) {
	int string_length = stringLength(s);

	// Allocate memory for a midifiable copy(+1 for null-terminate)
	char *copy = malloc(string_length + 1);
	if(!copy) return;

	// Copy the input string to the buffer
	stringCopy(copy, s);

	int result_string_length = stringLength(copy);

	printf("Before removing spaces: \"%s\" (len: %d)\n", copy, result_string_length);

	// Remove all spaces from the coppied string
    removeSpaces(copy);

    printf("After removing spaces: \"%s\"\n", copy);

	// Free the dynamically allocated buffer
	free(copy);
}
