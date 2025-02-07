
// Question: You will be given an undirected graph as input. Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

int dfs(int src)
{
    int count = 1;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (!vis[child])
            count += dfs(child);
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int x;
    cin >> x;

    memset(vis, false, sizeof(vis));
    int sz = dfs(x);
    cout << sz;

    return 0;
}

// in:
// 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2

// out:
// 4