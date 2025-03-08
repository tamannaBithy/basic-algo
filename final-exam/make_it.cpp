#include <bits/stdc++.h>
using namespace std;
bool dp[100005];
bool visited[100005];

bool reach(int n)
{

    if (visited[n])
        return dp[n];

    visited[n] = true;

    if (n == 1)
        return dp[n] = true;

    if (n < 1)
        return dp[n] = false;

    bool result = false;

    if (n % 2 == 0)
        result = result || reach(n / 2);
    result = result || reach(n - 3);

    return dp[n] = result;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        memset(dp, false, sizeof(dp));
        memset(visited, false, sizeof(visited));

        if (reach(n))
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
    return 0;
}