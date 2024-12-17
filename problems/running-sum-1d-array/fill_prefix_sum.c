#include <stdio.h>
#include <stdlib.h>

#define NUMS_SIZE 4


int* fillPrefixSum(int* nums, int numsSize, int* returnSum);


int main() {
	int nums[] = {1, 2, 3, 4};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int prefixSize = 0;	// sotore the size of prefix sum array
	int* prefixSum = NULL;

	prefixSum = fillPrefixSum(nums, numsSize, &prefixSize);
	for(int i = 0; i < prefixSize; i++) printf(" %d ", prefixSum[i]);	// print the prefix sum array
	printf("\n");

	free(prefixSum);	// free the allocation memory

	return 0;
}


int* fillPrefixSum(int* nums, int numsSize, int* returnSum) {
	*returnSum = numsSize;	// set the size of the returned array

	int* prefixSum = (int*) malloc(numsSize * sizeof(int));
	if (prefixSum == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if allocation fails
    }

	prefixSum[0] = nums[0];	// set the first element of prefix sum to the first element of the nums

	for(int i = 1; i < numsSize; i++)	// traverse from the second element until the last element of nums
	{
		/*	update the next element of prefix sum to the
			sum of previous element of prefix sum and next element of the nums
		*/
		prefixSum[i] = prefixSum[i-1] + nums[i];
	}

	return prefixSum;
}
