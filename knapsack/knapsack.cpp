#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];

int knapsack(int i, int mx_weight)
{

    if (i < 0 || mx_weight <= 0)
        return 0;

    // 2 ta option
    // 1. bage rakhbo, 2. bage rakhbo na

    if (weight[i] <= mx_weight)
    {
        int op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        return max(op1, op2);
    }
    else
    {
        // 1ta e option
        // bage rakhte parbo nah
        return knapsack(i - 1, mx_weight);
    }
}

int main()
{
    int n, mx_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> mx_weight;

    cout << knapsack(n - 1, mx_weight) << endl;

    return 0;
}

/// knapsack hoilo akta bager maximum weight deya thakle oi bager weight fulfill na hoya porjonto sorvoccho koto valuer jinis rakha jabe

/// complexity is O(2^n)