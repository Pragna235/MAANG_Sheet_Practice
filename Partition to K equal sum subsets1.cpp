/*
    Time Complexity: O(K * (2 ^ N))
    Space Complexity: O(N)

    Where 'N' is the size of the input array
    and 'K' is the number of non-empty subsets.
*/

bool canPartitionKSubsetsHelper(vector<int> &nums, int K, vector<bool> &vis, int targetSubsetSum, int curSubsetSum, int checkIdx) 
{

	// If all the K subsets have been formed successfully.
	if (K == 0) 
    {
		return true;
	}

	/* 
        If currentSubsetSum == targetSubsetSum, 
        reduce K by 1 and recur for helper function.
        Again we will check for all unvisited
        array elements to be put at next Subset.
    */
	if (curSubsetSum == targetSubsetSum) 
    {
		return canPartitionKSubsetsHelper(nums, K - 1, vis, targetSubsetSum, 0, 0);
	}

	/* 
        If not visited previously and adding it to the current
        subset <= targetSubsetSum, then you can vis it for further
        transitions or ignore it.
    */
	for (int i = checkIdx; i < nums.size(); i++) 
    {
		if (vis[i] == false && curSubsetSum + nums[i] <= targetSubsetSum) 
        {
			vis[i] = true;
			if (canPartitionKSubsetsHelper(nums, K, vis, targetSubsetSum, curSubsetSum + nums[i], i + 1)) 
            {
				return true;
			}

			vis[i] = false;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int> &nums, int N, int K) 
{
	int sum = 0;
	int maxNum = 0;
	for (int i = 0; i < nums.size(); i++) 
    {
		sum += nums[i];
		maxNum = max(maxNum, nums[i]);
	}

	// If total sum is not divisible by K or maximum number > eachSum.
	if (sum % K != 0 || maxNum > sum / K) 
    {
		return false;
	}

    vector<bool> vis(nums.size(),false);
	return canPartitionKSubsetsHelper(nums, K, vis, sum / K, 0, 0);
}
