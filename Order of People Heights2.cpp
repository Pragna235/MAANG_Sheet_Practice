/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)

    Where ‘N’ is the number of people.
*/

#include <algorithm>

vector<int> findOrder(vector<int> &height, vector<int> &infront) {
    // Number of people in a queue.
    int n = height.size();

    /* 
       Sort the array ‘Height’ in increasing order and arrange the elements
       of array ‘Infront’ such that ‘Height[i]’ and ‘Infront[i]’ represents 
       height and infront value of the same person after sorting.

       This can be done with help of matrix 'people'
    */
    vector<vector<int>> people(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        people[i][0] = height[i];
        people[i][1] = infront[i];
    }

    sort(people.begin(), people.end());
    
    for(int i = 0; i < n; i++) {
        height[i] = people[i][0];
        infront[i] = people[i][1];
    }
    

    // It will have actual order of people in a queue.
    vector<int> result(n);

    // Find actual position of each people in a queue. 
    for(int i = 0; i < n; i++) {
        int countEmpty = 0;
        // Find first index such that there are infront[i] empty slots before it.
        for(int j = 0; j < n; j++) {
            if(result[j] == 0 && countEmpty < infront[i]) {
                countEmpty++;
            }
            else if(result[j] == 0 && countEmpty == infront[i]) {
                result[j] = height[i];
                break;
            }
        }
    }
    
    return result;
}
