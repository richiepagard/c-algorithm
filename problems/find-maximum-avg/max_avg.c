#include <stdio.h>
#include <stdlib.h>

#define NUMS_SIZE 6


double find_max_average(int* nums, int numsSize, int k);


int main() {
    int windowSize = 4;
    int nums[NUMS_SIZE] = {1, 12, -5, -6, 50, 3};

    double result = find_max_average(nums, NUMS_SIZE, windowSize);

    printf("Max Sum Of The Array: %f\n", result);

    return 0;
}


double find_max_average(int* nums, int numsSize, int k) {
	/*	function to find the maximum average of any subarray of size `k` in an array
	*/

    double window_sum = 0, max_sum = 0;

    // calculate the sum of first window -the first `k` elements-
    for(int i = 0; i < k; i++) window_sum += nums[i];
    max_sum = window_sum;   // set maximum sum to the first window's sum

    // slide the window across the array, updating the sum and maximum sum
    for(int i = k; i < numsSize; i++) {
        /*  update the window sum by adding the next element
            and removing the first element of the previous window !
        */
        window_sum += nums[i] - nums[i - k];
        // update the maximum sum if the new window sum is greater
        if(max_sum < window_sum) max_sum = window_sum;
    }

    return max_sum/k;   // return the maximum average by dividing the maximum sum by `k`
}
