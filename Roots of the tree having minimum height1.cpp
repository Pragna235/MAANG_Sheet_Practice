/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)

    where 'N' is the number of nodes in the tree.
*/

#include <queue>

#define INT_MAX 1000000

// Function to find the height of a rooted tree using BFS.
int findHeight(int root, vector<vector<int>> &adj)
{
    vector<int> dis(adj.size(), INT_MAX);

    queue<int> q;
    q.push(root);
    dis[root] = 0;

    int height = 0;

    while (q.size())
    {
        int ele = q.front();
        q.pop();

        for (int i: adj[ele])
        {
            if (dis[i] == INT_MAX)
            {
                dis[i] = dis[ele] + 1;
                height = dis[i];
                q.push(i);
            }
        }
    }
    return height;
}

vector<int> minHeightRoots(vector<vector<int>> &edges)
{
    int n = edges.size() + 1;
    vector<vector < int>> adj(n + 1);

    // Building the adjacency list.
    for (int i = 0; i < (n - 1); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> rootsList;
    int minHeight = INT_MAX;

    // Iterating through all the nodes.
    for (int i = 1; i <= n; i++)
    {
        // Finding height of the tree rooted at Node i.
        int height = findHeight(i, adj);

        // Checking if the current height is the minimum height.
        if (height < minHeight)
        {
            minHeight = height;
            rootsList.clear();
            rootsList.push_back(i);
        }
        else if (minHeight == height)
        {
            rootsList.push_back(i);
        }
    }

    return rootsList;
}
