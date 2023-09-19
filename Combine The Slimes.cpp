/*
    Time Complexity : O(N^3)
    Space Complexity : O(N^2)

    Where, N is the size of the array.
*/

int recursion(int i, int j, vector<int> &slimes, vector<vector<int>> &dp, vector<vector<int>> &sum) {

	// Base case.
	if (i == j) {
		return 0;
	}

	// If we have already calculated dp[i][j] then return dp[i][j].
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// Take a pointer to dp[i][j].
	int &ans = dp[i][j];
	for (int k = i; k + 1 <= j; k++) {

		// Calculate the cost of combining slimes i to k and k+1 to j.
		int temp = recursion(i, k, slimes, dp, sum) + recursion(k + 1, j, slimes, dp, sum) + sum[i][k] * sum[k + 1][j];

		// Update ans if we found the minimum cost of the slime.
		if (ans == -1 || temp < ans)
			ans = temp;
	}

	// Return the minimum cost of combining slimes 0 to n-1.
	return ans;
}
int minCost(int n, vector<int> &slimes) {

	/*
	    Initialize dp with maximum value.
	    dp[i][j] means the minimum cost of combining
	    slimes from index i to index j.
	*/
	vector<vector<int>> dp(n + 1, (vector<int> (n + 1, -1)));
	vector<vector<int>> sum(n + 1, (vector<int> (n + 1, 0)));
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = i; j < n; j++) {
			s += slimes[j];
			sum[i][j] = s % 100;
		}
	}
	return recursion(0, n - 1, slimes, dp, sum);
}
