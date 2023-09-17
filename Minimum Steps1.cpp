/*
    Time Complexity: O(N^3)
    Space Complexity: O(1)

    Where N is the number of elements in the array
*/

#include <climits>

bool isEqual(vector<int> &arr)
{
    // Set X equal to first element
    int x = arr[0];

    for(int i = 0; i < arr.size(); i++)
    {   
        int num = arr[i];

        // If any element is not equal to the first element then return False
        if (num != x)
        {
            return false;
        }
    }

    // Return True if different element is not found
    return true;
}


int minimumSteps(int n, vector<int> &arr)
{
    int steps = 0;

    // While all the elements in the array are not equal
    while(!isEqual(arr))
    {
        int maxIndex = -1;
        int maxElement = INT_MIN;
        int secondMaxElement = INT_MIN;

        // Find the largest and the second largest elements in the array
        for(int index = 0; index < n; ++index)
        {
            if(arr[index] > maxElement)
            {
                secondMaxElement = maxElement;
                maxElement = arr[index];
                maxIndex = index;
            }
            else if(arr[index] > secondMaxElement && arr[index] != maxElement)
            {
                secondMaxElement = arr[index];
            }
        }

        // Replace the largest with the second largest in the array
        arr[maxIndex] = secondMaxElement;
        steps += 1;
    }

    // Finally return the the number of steps
    return steps;
}

