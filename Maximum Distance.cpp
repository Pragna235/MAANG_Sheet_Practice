/*
    Time Complexity: O((N^2)*M)
    Space Complexity: O(1)

    Where N is the number of strings and M is the average length of each string
*/

int calculateDistance(string &firstString, string &secondString)
{
    int i, j;
    i = j = 0;

    while(i < firstString.size() and j < secondString.size())
    {
        // If at any position the characters are not equal we break the loop
        if(firstString[i] != secondString[j])
        {
            break;
        }

        i += 1;
        j += 1;
    }

    // Return the distance at which both strings became unequal
    return firstString.size() - i + secondString.size() - j;
}

int maximumDistance(vector<string> &arr)
{
    int maxDistance = 0;

    // For each string iterate over every string
    for(int i = 0; i < arr.size(); i++)
    {   
        string firstString = arr[i];

        for(int j = 0; j < arr.size(); j++)
        {   
            string secondString = arr[j];

            /// Update the maximum distance
            maxDistance = max(maxDistance, calculateDistance(firstString, secondString));
        }
    }

    // Return the maxDistance
    return maxDistance;
}

