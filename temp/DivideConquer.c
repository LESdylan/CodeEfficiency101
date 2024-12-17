#include <stdio.h>
#include <limits.h>

int maxCrossingSum(int nums[], int left, int mid, int right) {
    int leftSum = -1000000000; // Valeur initiale très petite
    int rightSum = -1000000000;

    // Trouver la somme maximale à gauche de mid
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    // Trouver la somme maximale à droite de mid
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    // Retourner la somme maximale traversant le centre
    return leftSum + rightSum;
}

int maxSubArrayDivideConquer(int nums[], int left, int right) {
    if (left == right) {
        return nums[left]; // Base case: un seul élément
    }

    int mid = (left + right) / 2;

    // Appels récursifs pour les sous-tableaux gauche et droit
    int leftMax = maxSubArrayDivideConquer(nums, left, mid);
    int rightMax = maxSubArrayDivideConquer(nums, mid + 1, right);

    // Calcul de la somme maximale traversant le centre
    int crossMax = maxCrossingSum(nums, left, mid, right);

    // Retourner le maximum parmi les trois options
    return (leftMax > rightMax ? (leftMax > crossMax ? leftMax : crossMax) : (rightMax > crossMax ? rightMax : crossMax));
}
