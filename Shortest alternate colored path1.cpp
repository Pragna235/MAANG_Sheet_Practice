/*
    Time Complexity : O(N + (RLEN + BLEN) * log(RLEN + BLEN))
    Space Complexity : O(N + RLEN + BLEN)

    where 'RLEN' is the number of red edges, 
	'BLEN' is the number of blue Edges and 'N' is the number of nodes.
*/

#include <queue>

// Structure of 'Node' used in priority queue.
struct Node 
{
    int dist;
    int label;
    int color;
    bool operator<(const Node& a) const 
	{  
        return a.dist < dist;    
    }
};

vector<int> shortestAlternateColoredPath(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
{
    vector<int> graph[2][n];

    for (int i = 0; i < redEdges.size(); i++) 
	{
        graph[0][redEdges[i][0]].push_back(redEdges[i][1]);
    }
    for (int i = 0; i < blueEdges.size(); i++) 
	{  
		// Add blue edges to 'graph[1]'.
        graph[1][blueEdges[i][0]].push_back(blueEdges[i][1]);
    }

    vector<vector<int>> dist(n, vector<int>(2, 2 * n));
    dist[0][0] = dist[0][1] = 0;  

    priority_queue<Node> minDist;
    minDist.push({0, 0, 0});  
	// Source node with red incoming edge.
    minDist.push({0, 0, 1});  
	// Source node with blue incoming edge.

    while (!minDist.empty()) 
	{
        Node node = minDist.top();
        minDist.pop();

        int cur = node.label; 
        int c = node.color;    

        // If the path length of [cur, c] in 'node' is greater than 'dist[cur][c]' skip this node.
        if (dist[cur][c] < node.dist) continue;

        for (int i = 0; i < graph[1 - c][cur].size(); i++) 
		{
            int next = graph[1 - c][cur][i];  

            if (dist[next][1 - c] > dist[cur][c] + 1) 
			{
                dist[next][1 - c] = dist[cur][c] + 1;
                minDist.push({dist[next][1 - c], next, 1 - c});
            }
        }
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) 
	{  
		// Compute the array 'answer' from 'dist'.
        answer[i] = min(dist[i][0], dist[i][1]);
        if (answer[i] == 2 * n) answer[i] = -1;
    }

    return answer;
}
