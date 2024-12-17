#include <stdio.h>
#include <limits.h>

int maxSubArrayBruteForce(int nums[], int n) {
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}
