/*
https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/ Edge Existence
You have been given an undirected graph consisting of N nodes and M edges.
This graph can consist of self-loops as well as multiple edges.
In addition, you have also been given Q queries. For each query,
you shall be given 2 integers A and B. You just need to find if there exists
an edge between node A and node B. If yes, print "YES" (without quotes) else , print "NO"(without quotes).

Input Format:
The first line consist of 2 integers N and M denoting the number of nodes and edges respectively. Each of the next M lines consist of 2 integers A and B denoting an undirected edge between node A and B. The next line contains a single integer Q denoting the number of queries. The next Line contains 2 integers A and B denoting the details of the query.

Output Format:
Print Q lines, the answer to each query on a new line.

Constraints:
1 <= N <= 10^3
1 <= M <= 10^3
1 <= A, B <= N
1 <= Q <= 10^3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n + 1);

    for (int i = 0, x=0, y=0; i < m; ++i)
    {
        cin >> x >> y;
        A[x].emplace_back(y);
        A[y].emplace_back(x);
    }

    int q;
    cin >> q;

    for (int i = 0, x = 0, y = 0; i < q; ++i)
    {
        cin >> x >> y;
        auto it = find(A[x].begin(), A[x].end(), y);
        if (it != A[x].end())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}