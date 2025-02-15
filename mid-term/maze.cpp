#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
pair<int, int> parent[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'R' || grid[ci][cj] == 'D'))
            {

                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {pi, pj};
            }
        }
    }
}
int main()
{
    int si = 0, sj = 0, di = 0, dj = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            parent[i][j] = {-1, -1};
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }

    memset(vis, false, sizeof(vis));
    bfs(si, sj);

    int x = di, y = dj;

    while (1)
    {
        pair<int, int> p = parent[x][y];
        x = p.first;
        y = p.second;

        if ((x == -1 && y == -1) || grid[x][y] == 'R')
            break;

        grid[x][y] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }

        cout << endl;
    }

    return 0;
}

// in:
// 5 6
// ...D.#
// .##..#
// ....#.
// .R#...
// .#.##.

// out:
// ...D.#
// .##X.#
// .XXX#.
// .R#...
// .#.##.