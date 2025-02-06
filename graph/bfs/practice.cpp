#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool visited[100005];

int parent[100005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
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

    fill(visited, visited + n + 1, false);
    fill(parent, parent + n + 1, -1);

    memset(visited, false, sizeof(visited));

    memset(parent, -1, sizeof(parent));
    int src = 1, dst = n;
    bfs(src);

    if (!visited[dst])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    int node = dst;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int x : path)
        cout << x << " ";

    return 0;
}