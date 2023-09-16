/*
    Time complexity: O(N*log(N))
    Space complexity: O(N)
    
    where 'N' is the number of elements in the array.
*/

int maxIndexDiff(vector<int> &arr, int n) 
{
    // saving the indices along with the values.
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) 
    {
        vec.push_back({arr[i], i});
    }

    // sorting the vector.
    sort(vec.begin(), vec.end());

    // maintaining the suffix array, for the largest index.
    vector<int> suffix(n, 0);
    int currMax = INT_MIN, ans = 0;

    // inserting maximum value of index in our suffix array.
    for (int i = n - 1; i >= 0; i--) 
    {
        currMax = max(currMax, vec[i].second);
        suffix[i] = currMax;
    }

    // updating our final answer.
    for (int i = 0; i < n - 1; i++) 
    {
        ans = max(ans, suffix[i + 1] - vec[i].second);
    }

    // returning our final updated answer.
    if (ans == 0) 
    {   
        return -1;
    }
    
    return ans;
}
