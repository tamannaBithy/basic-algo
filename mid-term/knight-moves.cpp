#include <bits/stdc++.h>
using namespace std;
bool vis[101][101];
int level[101][101];
vector<pair<int, int>> d = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
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
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}

// 4
// 8 8
// 0 0
// 7 7
// 5 6
// 0 1
// 0 1
// 4 4
// 0 0
// 0 1
// 2 2
// 0 0
// 0 1