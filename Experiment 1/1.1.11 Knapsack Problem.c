#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int* values = (int*)malloc(N * sizeof(int));
    int* weights = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    int W;
    scanf("%d", &W);

    // dp array to store the maximum value for each capacity up to W
    // Using a 1D array of size (W + 1) to optimize memory usage to O(W)
    int* dp = (int*)calloc(W + 1, sizeof(int));

    // Process each item one by one
    for (int i = 0; i < N; i++) {
        // Traverse the dp array backwards to prevent using the same item multiple times
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
