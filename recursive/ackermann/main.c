#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursive_ackerman(int n, int m);


int main() {
	printf("\n");
	printf("%d\t", recursive_ackerman(1, 1));
	printf("%d\t", recursive_ackerman(2, 5));
	printf("%d\t", recursive_ackerman(3, 2));
	printf("%d\n\n", recursive_ackerman(4, 1));

	return 0;
}


int recursive_ackerman(int n, int m) {
	/*
		Recursive Ackerman Formula:
		The Ackermann function is a recursive function with deep theoretical significance due to its fast-growing nature.

		It is defined as:

			A(n, m) = 
				- m + 1								if n = 0
				- A(n - 1, 1)						if m = 0
				- A( n - 1, A(n, m - 1) )			if n > 0 and m > 0
		
		Explanation:
			- A(n, m) takes two non-negative integers 'n' and 'm'.
			- It is a deeply recursive function, where each recursive call reduces 'n' and/or 'm' until the base case is reached.

		Base Case:
			- When n = 0, the function simple returns m + 1.

		Recursive Cases:
			- When n > 0 and m = 0, the function returns A(n - 1, m - 1).
			- When n > 0 and m > 0, the function calls A( n - 1, A(n, m - 1) ).

		Ackermann Function Simplified Expressions for Small `n` Values:
		For small values of 'n', the Ackermann function has some simplified expressions. Below is the breakdown for specific values of 'n':

			- A(0, n) = m + 1
			- A(1, n) = m + 2
			- A(2, n) = 2 * m + 3
			- A(3, n) = 2^(m + 3) - 3
			- A(4, n) = 2^(2^(m + 3)) - 3
	*/
	int result;

	// simplified expressions for small `n` values
	switch(n)
	{
		case 0: return m + 1; break;
		case 1: return m + 2; break;
		case 2: return 2 * m + 3; break;
		case 3: return pow(2, m + 3) - 3; break;
		case 4: return pow(2, pow(2, m + 3)) - 3; break;
	}

	// base conditions
	result = 0;
	if(m == 0)	{
		result = recursive_ackerman(n -= 1, m = 1);
		return result;
	}
	else if(n > 0 && m > 0) {
		result = recursive_ackerman( n -= 1, recursive_ackerman(n, m -= 1) );
		return result;
	}
}
