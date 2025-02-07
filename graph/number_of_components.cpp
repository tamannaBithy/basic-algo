#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

int dfs(int si, int sj)
{

    vis[si][sj] = true;
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {

            count += dfs(ci, cj);
        }
    }

    return count;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    vector<int> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {

                int size = dfs(i, j);
                v.push_back(size);
            }
        }

    if (v.empty())
        cout << 0;
    else
    {
        sort(v.begin(), v.end());

        for (int x : v)
            cout << x << " ";
    }

    return 0;
}

// input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// output:
// 2 2 8