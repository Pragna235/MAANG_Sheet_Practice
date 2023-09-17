/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the size of the array.
*/

int findLength(vector<int> &arr, int n){

    // Starting and ending point of subarray.
    int start = -1;
    int end = -1;

    // To find the start point.
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1]){
            start = i;
            break;
        }
    }
    // If already sorted.
    if (start == -1){
        return 0;
    }

    // To find the end point.
    for (int i = n - 1; i > 0; i--){
        if (arr[i] < arr[i - 1]){
            end = i;
            break;
        }
    }
    int max = arr[start];
    int min = arr[start];

    // Find max and min of subarray.
    for (int i = start + 1; i < end + 1; i++){
        if (max < arr[i]){
            max = arr[i];
        }
        if (min > arr[i]){
            min = arr[i];
        }
    }
    // Check for other conditions.
    for (int i = 0; i < start; i++){
        if (arr[i] > min){
            start = i;
            break;
        }
    }
    for (int i = n - 1; i > end; i--){
        if (arr[i] < max){
            end = i;
            break;
        }
    }

    if (end > start){
        return end - start + 1;
    }
    return 0;
}
