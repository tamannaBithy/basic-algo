// Question: You will be given an undirected graph which will be connected as input. Then you will be given a level L. You need to print the node values at level L in descending order. The source will be 0 always.

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

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
                level[child] = level[par] + 1;
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

    memset(visited, false, sizeof(visited));

    bfs(0);

    vector<int> val;

    for (int i = 0; i < n; i++)
    {
        if (level[i] == 1)
            val.push_back(i);
    }

    reverse(val.begin(), val.end());

    for (int x : val)
        cout << x << " ";

    return 0;
}

// input :
// 6 7
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 3 5
// 4 3
// 1

// output :
// 3 2 1