/*
    Time complexity: O(N*log(N))
    Space complexity: O(N)

    Where 'N' is the size of the array.
*/

#include <algorithm>

int findLength(vector<int> &arr, int n){

    // Copy of array.
    vector<int> arrCopy;
    for (auto i : arr){
        arrCopy.push_back(i);
    }
    // Sorting the array.
    sort(arrCopy.begin(), arrCopy.end());

    // Starting and ending point of subarray.
    int start = n;
    int end = 0;

    for (int i = 0; i < n; i++){
        // Find mismatched elements.
        if (arrCopy[i] != arr[i]){

            // Update start and end.
            start = min(start, i);
            end = max(end, i);
        }
    }
    if (end > start){
        return end - start + 1;
    }
    return 0;
}
