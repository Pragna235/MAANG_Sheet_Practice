/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    Where N is the number of elements in the array.
*/

#include <algorithm>

int minimumSteps(int n, vector<int> &arr)
{
    // If a single element is present return 0
    if(arr.size() < 2)
    {
        return 0;
    }

    // Sorting the array in no increasing order
    sort(arr.begin(), arr.end(), greater<int>());

    int steps = 0;

    // Iterating through the array
    for(int index = 0; index < n; index++)
    {
        // If the element is different from previous element add the number of steps
        if(arr[index - 1] > arr[index])
        {
            steps += index;
        }
    }

    // Return the final no of steps
    return steps;
}

