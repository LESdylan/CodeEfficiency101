#include <stdio.h>
#include <limits.h>

int maxSubArrayCumulatedSum(int nums[], int n) {
    int prefixSum[n + 1];
    prefixSum[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int currentSum = prefixSum[j] - prefixSum[i];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}
