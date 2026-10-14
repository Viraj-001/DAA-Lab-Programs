#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int n;
int cost[20][20];
int dp[1 << 16][16];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    // Base case: If all cities have been visited
    if (mask == (1 << n) - 1) {
        // Return cost from current city back to the starting city (0)
        return (cost[pos][0] != -1) ? cost[pos][0] : INF;
    }

    // If this state has already been computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try to visit all other unvisited cities
    for (int nxt = 0; nxt < n; nxt++) {
        // Check if the city is not visited yet and a valid path exists
        if ((mask & (1 << nxt)) == 0 && cost[pos][nxt] != -1) {
            int new_cost = cost[pos][nxt] + tsp(mask | (1 << nxt), nxt);
            ans = min(ans, new_cost);
        }
    }

