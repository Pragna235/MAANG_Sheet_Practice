/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where N is the length of the string
*/

#include <unordered_set>

int kDistinctChars(int k, string &str)
{
    int ans = 0;

    for(int i = 0; i < str.length(); i++)
    {
        // Create a set of unique characters
        unordered_set<char> uniqueChars;

        for(int j = i; j < str.length(); j++)
        {
            // Add characters in the set
            uniqueChars.insert(str[j]);

            // If set size is greater than K then we won't consider this substring
            if(uniqueChars.size() > k)
            {
                break;
            }

            // Update the answer
            ans = max(ans, j - i + 1);
        }
    }

    return ans;
}





