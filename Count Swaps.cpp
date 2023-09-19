/*
    Time complexity: O(N ^ 2)
    Space complexity: O(1)
    
    Where 'N' is the size of the string.
*/

int countSwaps(string &str){
    
    // Calculate length of string.
    int n = str.size();
    
    // Map to store the count of all letters.
    unordered_map< char , int > d;
    
    for(int i = 0; i < n; ++i){
        d[str[i]]++;
    }
    
    int count = 0;
    
    // Check count for each letter.
    for(auto i : d){
        if(i.second % 2){
            ++count;
        }
    }
    
    // If number of odd count letter is greater than 1.
    if(count > 1){
        return -1;
    }
    
    // To store number of swaps.
    count = 0;
    
    // Initialise two-pointers.
    int i = 0;
    int j = n - 1;
    
    while(i < j){
        
        // If they match.
        if(str[i] == str[j]){
            ++i;
            --j;
        }
        else{
            int temp = j;
            
            // Find matching letter.
            while(str[temp] != str[i]){
                --temp;
            }
            
            if(str[temp]==str[i]){
                
                // Swap.
                swap(str[temp], str[temp + 1]);
                
                // Increment count.
                ++count;
            }
            else{
                for(int k = temp; k < j; ++k){
                    
                    // Swap.
                    swap(str[k], str[k + 1]);
                    
                    // Increment count.
                    ++count;
                }
                ++i;
                --j;
            }
        }
    }
    return count;
}
