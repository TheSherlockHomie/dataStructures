/*
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Given a directed graph. The task is to do Breadth First Search of this graph.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
You don't need to read input or print anything. Your task is to complete the function bfs() takes the Graph and the number of vertices as its input and returns a list containing the BFS traversal of the graph starting from the 0th vertex.

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
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
2 is connected to 4
so starting from 0 , bfs will be 0 1 2 3 4.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>&);

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

        vector<int> ans = bfs(adj);
        
        for (auto x : ans)
            cout << x << " ";
    }
}

vector<int> bfs(vector<vector<int>>& adj)
{
    vector<int> orderOfVisit;

    vector<bool> visited(adj.size(), 0);

    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        orderOfVisit.push_back(x);

        for (int j = 0; j < adj[x].size(); ++j)
        {
            if (!visited[adj[x][j]])
            {
                visited[adj[x][j]] = 1;
                q.push(adj[x][j]);
            }
        }
    }

    return orderOfVisit;
}
