/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
      public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

/*
    Time Complexity     :   O(N)
    Space Complexity    :   O(N)

    Where 'N' is the number of nodes in the binary tree.
*/

#define FLOAT_MIN - 1e9

// Recursive function to traverse the tree in post order.
vector<int> postOrderTraversal(TreeNode<int> *currRoot, double &maxAverage) {
    // Checking if the current node is 'NULL'.
    if (currRoot == NULL) {
        return {0, 0};
    }

    // Traversing the left and right subtrees.
    vector<int> leftSubtreeResults = postOrderTraversal(currRoot->left, maxAverage);
    vector<int> rightSubtreeResults = postOrderTraversal(currRoot->right, maxAverage);

    // Finding the sum of nodes and the number of nodes.
    int currSum = leftSubtreeResults[0] + rightSubtreeResults[0] + currRoot->data;

    int currNodes = leftSubtreeResults[1] + rightSubtreeResults[1] + 1;

    // Updating the overall maximum average.
    maxAverage = max(maxAverage, (double) currSum / currNodes);

    return {currSum, currNodes};
}

double maxSubtreeAverage(TreeNode<int> *root) {
    double maxAverage = FLOAT_MIN;

    // Traversing the tree in post-order.
    postOrderTraversal(root, maxAverage);

    // Returning the updated value.
    return maxAverage;
}
