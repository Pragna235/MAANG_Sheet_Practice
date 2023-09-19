/*
    Time Complexity : O(N^3)
    Space Complexity : O(N^2)

    Where, N is the size of the array.
*/

int minCost(int n, vector<int> &slimes) {

    /*
        Initialize dp with maximum value.
        dp[i][j] means the minimum cost of combining
        slimes from index i to index j.
    */
    vector<vector<int>> dp(n + 1, (vector<int> (n + 1, 1e9)));
    vector<vector<int>> sum(n + 1, (vector<int> (n + 1, 0)));

    // Cost of combining single slime is 0.
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    /*
        Calculate the size of slime after combining
        every slime between index i to j.
    */
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += slimes[j];
            sum[i][j] = s % 100;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // skip calculating dp if the range goes beyond n.
            if (j + i >= n) {
                continue;
            }
            for (int k = j; k < j + i; k++) {

                // Update the minimum cost of combining two slimes.
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j][k] * sum[k + 1][j + i]);
            }
        }
    }

    // Return the final cost of combining slimes from 0 to n-1.
    return dp[0][n - 1];
}
