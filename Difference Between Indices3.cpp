/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    where 'N' is the number of elements in the array.
*/

int maxIndexDiff(vector<int> &arr, int n)
{
    int ans;
    int i, j;
 
    // maintaining our prefix, suffix arrays.
    vector<int> prefix(n);
    vector<int> suffix(n);
 
    // Constructing the prefix array 
    prefix[0] = arr[0];

    for (i = 1; i < n; ++i)
    {
        prefix[i] = min(arr[i], prefix[i - 1]);
    }
 
    // constructing the suffix array
    suffix[n - 1] = arr[n - 1];

    for (j = n - 2; j >= 0; --j)
    {
        suffix[j] = max(arr[j], suffix[j + 1]);
    }
 
    i = 0, j = 0, ans = -1;
    
    // traverse both arrays from left to right to find optimum j - i. 
    while (j < n && i < n) 
    {
        if (prefix[i] <= suffix[j]) 
        {
            ans = max(ans, j - i);
            j = j + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    
    // return the final updated answer.
    if(ans == 0)
    {
        return -1;
    }

    return ans;
}
