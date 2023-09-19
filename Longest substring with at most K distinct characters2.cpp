/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is the length of the string
*/

#include <unordered_map>

int kDistinctChars(int k, string &str)
{
    // Initialise left and right pointers
    int left = 0;
    int right = 0;

    int maxLength = 0;

    // Initialise map of characters
    unordered_map<char, int> uniqueChars;

    // While the right pointers does not reach the end of the loop
    while(right < str.length())
    {
        // Add the right most character of the string in the  map
        char rightCh = str[right];

        uniqueChars[rightCh] = uniqueChars[rightCh] + 1;  
        
        // If the set has move than k unique characters then start decreasing the window from left
        while(uniqueChars.size() > k)
        {
            char leftCh = str[left];

            // If leftCh is present in map decrease it
            if(uniqueChars.count(leftCh) == 1)
            {
                uniqueChars[leftCh] -= 1;

                // Remove the character from the map if it becomes 0
                if(uniqueChars[leftCh] == 0)
                {
                    uniqueChars.erase(leftCh);
                }
            }

            // Decrease the sliding window from left side
            left += 1;
        }

        maxLength = max(maxLength, right - left + 1);

        // Increase the sliding window from the right
        right += 1;
    }

    return maxLength;
}

