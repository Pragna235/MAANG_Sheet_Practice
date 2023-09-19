/*
    Time Complexity : O(N*log(N))
    Space Complexity : O(N)

    Where 'N' is the number of people.
*/

#include <algorithm>

void buildSegTree(vector<int> &tree, int root, int left, int right) {
    if(left == right) {
        // Leaf node will have a single empty slot initially
        tree[root] = 1;
    }
    else {
        int mid = (left + right) / 2;
        // Recurse on the left child
        buildSegTree(tree, 2*root+1, left, mid);
        // Recurse on the right child
        buildSegTree(tree, 2*root+2, mid+1, right);
        // Internal node will have the sum of both of its children
        tree[root] = tree[2*root+1] + tree[2*root+2];
    }
}

int findEmptySlot(vector<int> &tree, int root, int left, int right, int k) {
    // One slot in the range represented by root will be occupied. 
    tree[root]--;

    if(left == right) {
        // We have find the required empty slot.
        return left;
    }

    int mid = (left + right) / 2;

    /* 
        If number of empty slot in first half is more than k,
        then our desired slot will be Kth empty slot of first half of current range
        so we recurse on first half of current range.
    */
    if(tree[2*root+1] >= k) {
        return findEmptySlot(tree, 2*root+1, left, mid, k);
    }

    /*
        Our desired slot will be (k - number of empty slot in first half)th slot 
        of second half current of range so we recurse on second half of current range.
    */
    return findEmptySlot(tree, 2*root+2, mid+1, right, k-tree[2*root+1]);
}

vector<int> findOrder(vector<int> &height, vector<int> &infront) {
    // Number of people in a queue.
    int n = height.size();

    /* 
       Sort the array 'Height' in increasing order and arrange the elements
       of array 'Infront' such that 'Height[i]' and 'Infront[i]' represents 
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

    // Recursively build segment tree. 
    vector<int> tree(4*n);
    buildSegTree(tree, 0, 0, n-1);

    // It will have actual order of people in a queue.
    vector<int> result(n);

    // Find empty slot for each person, andd update segment tree accordingly.
    for(int i = 0; i < n; i++) {
        int slot = findEmptySlot(tree, 0, 0, n-1, infront[i]+1);
        result[slot] = height[i];
    }
    
    return result;
}
