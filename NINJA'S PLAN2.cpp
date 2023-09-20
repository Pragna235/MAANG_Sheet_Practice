/*
    Time complexity: O(N)
    Space complexity: O(N) 

    Where  N represents the size of array.
*/

vector<int> ninjaPlan(vector<int> &heightArr, int n)
{
	int max = 0;
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--)
	{
		// Checking if heightArr is greater than max.
		if (heightArr[i] > max)
		{
			max = heightArr[i];
			ans.push_back(i);
		}
	}

	// Reversing the array.
	reverse(ans.begin(), ans.end());
	return ans;
}
