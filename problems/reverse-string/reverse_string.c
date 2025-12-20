#include <stdio.h>

#define MAX_LINE_SIZE 30


void reverse_per_line(void);

int main() {
	char string[30] = "richie";

	reverse_per_line();

	return 0;
}


void reverse_per_line(void) {
	/* Reverse the input one line at a time.
	 * Task:
	 *		Write a function that reverses a character string, and
	 *		use it to build a program that reverses its input line by line.
	 */
	int character;
	int counter;
	// Indices used while reversing the buffer
	int first, last;

	// Buffer to store the original line
	char buffer[MAX_LINE_SIZE];
	// Buffer to store the reversed result
	char reversed[MAX_LINE_SIZE];

	counter = first = 0;
	while ((character = getchar()) != EOF)
	{
		if (character == '\n') {
			// 'last' marks the last valid character in the buffer
			last = counter - 1;
			first = 0;

			// Copy characters from the end of 'buffer'
			// into 'reversed' starting from the beginning
			while (last >= 0) reversed[first++] = buffer[last--];

			// Null-terminate the reversed string
			reversed[first] = '\0';

			// Print the reversed line
			for (int i = 0; i < first; ++i) putchar(reversed[i]);
			putchar('\n');

			counter = 0;
			continue;
		}

		// Store characters in buffer until the maximum allowed size
		if (counter < MAX_LINE_SIZE-1) {
			buffer[counter++] = character;
		}
	}

	putchar('\n');
}
