#include <stdio.h>

#define MAX_LINE_SIZE 30


void reverse_per_line(void);

int main() {
	char string[30] = "richie";

	reverse_per_line();

	return 0;
}


void reverse_per_line(void) {
	/* Reverse gotten input per-line.
	 * Short Description:
	 *		Write a function reverse(sequence) that reverses the character string sequence.
	 *		Use it to write a program that reverses its input a line at a time.
	 */
	int character;
	int counter;
	// Indices used while reversing
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
			last = counter;

			// Copy characters from the end of 'buffer'
			// into 'reversed' starting from the beginning
			while (last >= 0) {
				reversed[first] = buffer[last];
				--last;
				++first;
			}

			// Null-terminate the reversed string
			reversed[counter+1] = '\0';
		}

		// Store characters in buffer until the maximum allowed size
		if (counter < MAX_LINE_SIZE-1) {
			buffer[counter++] = character;
		}
	}

	putchar('\n');
	printf("The Buffer Content: \n");
	for (int i = 0; i < MAX_LINE_SIZE; ++i) printf("%c", buffer[i]);
	putchar('\n');
	putchar('\n');

	printf("The Reversed Sequence Content: \n");
	for (int i = 0; i < MAX_LINE_SIZE; ++i) printf("%c", reversed[i]);
	putchar('\n');
}
