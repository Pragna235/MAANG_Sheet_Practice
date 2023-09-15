/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)

    where 'N' is the number of elements in 'ARR'.
*/

int decreasingSubsequences(int n, vector<int> &arr)
{
    // used[i] will store weather we can add an element after arr[i] or not.
    vector<int> used(n, 1);

    // ans will store the number of Subsequences.
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int index = -1;
        for (int j = 0; j < i; j++)
        {
            if (used[j] == 1 && arr[j] > arr[i])
            {
                if (index == -1)
                {
                    index = j;
                }
                else
                {
                    if (arr[j] - arr[i] < arr[index] - arr[i])
                    {
                        index = j;
                    }
                }
            }
        }

        // No suitable element found.
        if (index == -1)
            ans = ans + 1;
        else
        {
            // arr[i] is placed after arr[index].
            used[index] = 0;
        }
    }

    return ans;
}
