#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<long long>> adj_mat(n + 1, vector<long long>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {

                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
            }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (adj_mat[x][y] == LLONG_MAX)
            cout << "-1" << endl;
        else
            cout << adj_mat[x][y] << endl;
    }

    return 0;
}