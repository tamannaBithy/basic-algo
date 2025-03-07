#include <bits/stdc++.h>
using namespace std;

bool rec(long long int n)
{
    if (n == 1)
        return true;

    if (n % 10 != 0 && n % 20 != 0)
        return false;

    bool result = false;

    if (n % 20 == 0)
        result = result || rec(n / 20);
    if (n % 10 == 0)
        result = result || rec(n / 10);

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (rec(n))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}