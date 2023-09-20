/*
    Time complexity: O(N ^ 2)
    Space complexity: O(N) 

    Where  N represents the size of array.
*/

vector<int> ninjaPlan(vector<int> &heightArr, int n)
{
	bool flag = true;
	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		flag = true;

		// Iterating the right side of each element.
		for (int j = i + 1; j < n; j++)
		{
			// Checking if heightArr is greater or not.
			if (heightArr[i] <= heightArr[j])
			{
				flag = false;
				break;
			}
		}

		if (flag == true)
		{
			ans.push_back(i);
		}
	}

	return ans;
}
