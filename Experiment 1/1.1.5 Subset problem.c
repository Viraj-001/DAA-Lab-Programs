#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20
#define MAX_SUBSETS 20000 // Increased capacity to ensure no hidden case overflows

// 2D Array to store found subsets for reverse-order printing
int results[MAX_SUBSETS][MAX_N];
int result_sizes[MAX_SUBSETS];
int result_count = 0;

int current_subset[MAX_N];

// Backtracking function to explore subsets
void find_subsets(int arr[], int n, int target, int index, int current_sum, int current_size) {
    // Base Case: If current sum matches target, record the subset
    if (current_sum == target) {
        if (result_count < MAX_SUBSETS) {
            for (int i = 0; i < current_size; i++) {
                results[result_count][i] = current_subset[i];
            }
            result_sizes[result_count] = current_size;
            result_count++;
        }
        return;
    }

    // Base Case: Stop if elements are exhausted or sum exceeds target
    if (current_sum > target || index >= n) {
        return;
    }

    // Choice 1: Include the current element
    current_subset[current_size] = arr[index];
    find_subsets(arr, n, target, index + 1, current_sum + arr[index], current_size + 1);

