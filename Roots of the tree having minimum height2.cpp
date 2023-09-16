/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the number of nodes in the tree.
*/

#include <queue>

vector<int> minHeightRoots(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1);

    // Case when there is no leaf node in the tree.
    if (n == 1)
    {
        vector<int> ans(1, 1);
        return ans;
    }

    // Building the adjacency list.
    for (int i = 0; i < (n - 1); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    queue<int> q;

    // Adding all the leaf nodes into the queue.
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }

    int treeSize = n;
    while (treeSize > 2)
    {
        // Finding the number of nodes to be removed im current iteration.
        int currSize = q.size();
        treeSize -= currSize;

        for (int i = 1; i <= currSize; i++)
        {
            // Removing an element from the queue.
            int currElement = q.front();
            q.pop();

            // Iterating through its adjacent nodes.
            for (int currNeighbour: adj[currElement])
            {
                degree[currNeighbour]--;

                // Checking if the updated degreee of the node is equal to 1.
                if (degree[currNeighbour] == 1)
                {
                    q.push(currNeighbour);
                }
            }
        }
    }

    vector<int> ans;

    // Adding all element of the queue into the output array.
    while (q.size())
    {
        int ele = q.front();
        q.pop();

        ans.push_back(ele);
    }

    // Sorting the output array.
    if (ans.size() == 2 && ans[0] > ans[1])
    {
        swap(ans[0], ans[1]);
    }

    return ans;
}
