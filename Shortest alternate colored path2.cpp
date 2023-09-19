/*
    Time Complexity : O(N + RLEN + BLEN)
    Space Complexity : O(N + RLEN + BLEN)

    where 'RLEN' is the number of red edges, 
	'BLEN' is the number of blue Edges and 'N' is the number of nodes.
*/

#include <queue>

vector<int> shortestAlternateColoredPath(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
{
    vector<int> graph[2][n];

    for (int i = 0; i < redEdges.size(); i++) 
	{
        graph[0][redEdges[i][0]].push_back(redEdges[i][1]);
    }
    for (int i = 0; i < blueEdges.size(); i++) 
	{
        graph[1][blueEdges[i][0]].push_back(blueEdges[i][1]);
    }

    vector<vector<int>> dist(n, vector<int>(2, 2 * n));
    dist[0][0] = dist[0][1] = 0;  

    queue<pair<int, int>> bfsQ;
	// Source node with red incoming edge.
    bfsQ.push(make_pair(0, 0));  
	// Source node with blue incoming edge.
    bfsQ.push(make_pair(0, 1));  

    while (!bfsQ.empty()) 
	{
        int x = bfsQ.front().first;  
        int c = bfsQ.front().second; 
        bfsQ.pop();

        for (int i = 0; i < graph[1 - c][x].size(); i++) 
		{
            int next = graph[1 - c][x][i];  
			// Neighboring node with alternate color edge.

            if (dist[next][1 - c] > dist[x][c] + 1) 
			{
                dist[next][1 - c] = dist[x][c] + 1;
                bfsQ.push(make_pair(next, 1 - c));
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
