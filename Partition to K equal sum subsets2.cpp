/*
    Time Complexity: O(N * (2 ^ N))
    Space Complexity: O(2 ^ N)

    Where 'N' is the size of the input array.
*/

#include<cstring>

bool canPartitionKSubsets(vector<int>& nums, int n, int K)
{
    int dp[(1 << n) + 1];
    memset(dp, -1, sizeof dp);

    // Calculate the sum of all the numbers in the input array.
    int tot = 0;
    for (int i = 0; i < nums.size(); i++) {
        tot += nums[i];
    }

    // If the total sum isnt divisible by k, then return false.
    if (tot % K != 0) {
        return false;
    }

    // Sum of each of the K subsets is eachSum.
    int eachSum = tot / K;

    // Base case: (mask = 0, no element is chosen, so sum = 0).
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        
		// If the current mask is not reachable yet, skip further transitions from it.
        if (dp[mask] == -1) {
            continue;
        }

        for (int i = 0; i <= n - 1; i++) {
           
		    /*
			    If ith element was not present in mask subset, && sum <= target,
			    add it to this subset.
			*/
            if ( !(mask & (1 << i)) &&  dp[mask] + nums[i] <= eachSum) {
                dp[mask | (1 << i)] = dp[mask] + nums[i];
				
                /*
				    Make sum modulo eachSum, so that dp stores value
					that exceeds to make all subset sums equal till current transition.
				*/
                dp[mask | (1 << i)] %= eachSum;

                // Check if dp[(1<<n)-1] == 0 at any point, then return true.
                if (dp[mask | (1 << i)] == 0 && (mask | (1 << i)) == ((1 << n) - 1)) {
                    return true;
                }

            }

        }

    }

    return false;
}
