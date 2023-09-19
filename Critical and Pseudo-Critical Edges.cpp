/*
	Time Complexity : O(M ^ 2).
	Space Complexity : O(N * M).

	Where 'N' is the number of nodes,
    and 'M' is the number of edges.
*/

#include <algorithm>

// Find the representative.
int findParent(int x, vector<int> &parent)
{
	if (x == parent[x])
	{
		return x;
	}

	return (parent[x] = findParent(parent[x], parent));
}

// Find union of two sets.
void unionIt(int x, int y, vector<int> &rank, vector<int> &parent)
{
	int parentX = findParent(x, parent), parentY = findParent(y, parent);

	if (parentX == parentY)
	{
		return;
	}

	if (rank[parentX] > rank[parentY])
	{
		swap(parentX, parentY);
	}

	parent[parentX] = parentY;

	if (rank[parentX] == rank[parentY])
	{
		rank[parentY]++;
	}
}

// Find minimum spanning tree.
int getMST(const int n, const vector<vector<int>>& edges, int blockedge, int preEdge = -1)
{
	vector<int> parent, rank;

	rank = vector<int>(n, 1);

	parent.resize(n);

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	int weight = 0;

	if (preEdge != -1)
	{
		weight += edges[preEdge][2];
		unionIt(edges[preEdge][0], edges[preEdge][1], rank, parent);
	}

	for (int i = 0; i < edges.size(); ++i) {
		if (i == blockedge)
		{
			continue;
		}

		const auto& edge = edges[i];
		if (findParent(edge[0], parent) == findParent(edge[1], parent))
		{
			continue;
		}

		unionIt(edge[0], edge[1], rank, parent);
		weight += edge[2];
	}

	for (int i = 0; i < n; ++i)
	{
		if (findParent(i, parent) != findParent(0, parent))
		{
			return 1e9 + 7;
		}
	}

	return weight;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
{
	for (int i = 0; i < edges.size(); ++i)
	{
		edges[i].push_back(i);
	}

	sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) { //sorting the edges vector based on the weights
		return a[2] < b[2];
	});

	int minWt = getMST(n, edges, -1);

	vector<int> critical, pseudoCritical;

	for (int i = 0; i < edges.size(); ++i)
	{
        // If removing the edge makes same cost, it is a critical.
		if (minWt < getMST(n, edges, i))
		{
			critical.push_back(edges[i][3]);
		}
        // If force adding it does not change cost, it is pseudo critical.
		else if (minWt == getMST(n, edges, -1, i))
		{
			pseudoCritical.push_back(edges[i][3]);
		}
	}
	
	if (critical.empty())
	{
		critical.push_back(-1) ;
	}

	if (pseudoCritical.empty())
	{
		pseudoCritical.push_back(-1) ;
	}

	return {critical, pseudoCritical};
}
