#include <stdio.h>
#include <stdlib.h>

int recursive_combination(int n, int m);


int main() {
	printf("%d\n", recursive_combination(5, 3));

	return 0;
}

int recursive_combination(int n, int m) {
	/*
	    Binomial Coefficient Formula:

           n!
	    C(n, m) = --------
            m! (n - m)!

		Where:
        - n! is the factorial of n
        - m! is the factorial of m
        - (n - m)! is the factorial of (n - m)

		This formula is used to compute the number of ways to choose 'm' elements from a set of 'n' elements.


		Recursive Combination Formula:

		C(n, m) = C(n-1, m) + C(n-1, m-1)

		Where:
			- C(n, m) is the number of ways to choose 'm' elements from a set of 'n' elements.
			- The base cases are:
				* C(n, 0) = 1 (There is only one way to choose 0 elements)
				* C(n, n) = 1 (There is only one way to choose all 'n' elements)

		This recursive formula breaks down the problem into smaller subproblems by reducing 'n' and/or 'm' until the base case is reached.
	 */

	if( (n == m) || (m == 0) ) return 1;
	else
	{
		return recursive_combination(n-1, m) + recursive_combination(n-1, m-1);
	}

}

