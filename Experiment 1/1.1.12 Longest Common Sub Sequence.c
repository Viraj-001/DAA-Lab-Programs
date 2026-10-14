#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

int max(int a, int b){if(a>b){return a;}else{return b;}}

int lcsOf3(char X[], char Y[], char Z[], int m, int n, int o){
	
	if (m > 0 && X[m - 1] == '\n') m--;
	if (n > 0 && Y[n - 1] == '\n') n--;
	if (o > 0 && Z[o - 1] == '\n') o--;

	// 3D DP table initialized to 0
	int dp[m + 1][n + 1][o + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= o; k++) {
				// Base Case: If any string is empty, LCS is 0
				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] = 0;
				} 
				// If all three characters match
				else if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]) {
					dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
				} 
				// If characters mismatch, find the max of all 3 directional choices
				else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}

	return dp[m][n][o];
}
