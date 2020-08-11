/*
https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the nodes while doing DFS starting from node 0.

Your task:
You don't need to read input or print anything. Your task is to complete the function dfs() which takes the Graph and the number of vertices as inputs and returns a list containing the DFS Traversal of the graph starting from the 0th node.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3
0 1 2 3

*/

#include <iostream>
#include <vector>

using namespace std;

class soln
{
private:
    vector<vector<int>> adj;
    vector<int> orderOfVisit;
    vector<bool> visited;

    void dfsUtil(int node)
    {
        if (!visited[node])
        {
            visited[node] = true;
            orderOfVisit.push_back(node);

            for (int i = 0; i < adj[node].size(); ++i)
            {
                dfsUtil(adj[node][i]);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& graph, int nodes)
    {
        adj = graph;
        visited = vector<bool>(nodes, 0);

        dfsUtil(0);

        return orderOfVisit;
    }
};

vector<int> dfs(vector<vector<int>>&);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, e;
        cin >> n >> e;

        vector<vector<int>> adj(n);

        for (int i = 0; i < e; ++i)
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b); //directed graph
        }

        vector<int> ans = dfs(adj);

        for (auto x : ans)
            cout << x << " ";
    }
}

vector<int> dfs(vector<vector<int>>& adj)
{
    soln s;
    return s.dfs(adj, adj.size());
}