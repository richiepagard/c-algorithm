#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPalindrome(char *s);

int main() {
	bool is_palindrome = isPalindrome("A man, a plan, a canal: Panama");

	if(is_palindrome) printf("The string is palindrome.\n");
	else printf("The string isn't palindrome.\n");

	// Problem link on Leetcode
	char *problem_link = "https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150";

	return 0;
}


int stringLength(char *string) {
	int counter = 0;

	// Count characters until the null-terminate is reached
	while(string[counter] != '\0') counter++;

	// Return the length of the string(excluding null-terminate)
	return counter;
}

void stringCopy(char *copied_str, char *main_str) {
	int i = 0, j = 0;

	// Copy only ascii letters (a-z, A-Z) one by one until the null-terminate is reached
	while(main_str[i] != '\0') {
		char character = main_str[i];

		if(
			(character >= 'a' && character <= 'z') ||
			(character >= 'A' && character <= 'Z') ||
			(character >= '0' && character <= '9')
		)
		{
			// Convert uppercase letters to lowercase
			if(character >= 'A' && character <= 'Z') character = character + 'a' - 'A';

			copied_str[j++] = character;
		}
		i++;
	}

	copied_str[j] = '\0';

	printf("%s\n", copied_str);
}

bool isPalindrome(char *s) {
	int string_length = stringLength(s);
    int left, right;

	// Allocate memory for a modifiable copy(+1 for null-terminate)
	char *copy = malloc(string_length + 1);
	if(!copy) return 0;

	// Copy the input string to the buffer
	stringCopy(copy, s);

	int copy_string_length = stringLength(copy);
    left = 0;
    right = copy_string_length - 1;

    while(left <= right)
    {
		// Check string for palindrome
        if(copy[left] != copy[right]) return false;

		left++;
		right--;
    }

	// Free the dynamically allocated buffer
	free(copy);

    return true;
}
