/*
    Time complexity: O(N^2)
    Space complexity: O(1)
    
    where 'N' is the number of elements in the array.
*/

int maxIndexDiff(vector<int> &arr, int n)
{
    // initialising our answer as -1.   
    int ans = -1;
    int i, j;
 
    // running two nested for loops to check for the maximum difference.
    for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j) 
        {
            if (arr[j] > arr[i] && ans < (j - i))
                ans = j - i;
        }
    }
    
    // returning the maximum answer. 
    return ans; 
}
