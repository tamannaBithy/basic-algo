// Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.

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

    memset(vis, false, sizeof(vis));

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            v.push_back(dfs(i));
    }

    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";

    return 0;
}

// in:
// 10 5
// 1 2
// 2 3
// 1 3
// 4 0
// 5 6

// out:
// 1 1 1 2 2 3
