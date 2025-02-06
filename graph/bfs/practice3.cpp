
// Question: You will be given an undirected graph as input. Then you will be given a node N. You need to print the number of nodes that are directly connected to the node N.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[1005];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int x;
    cin >> x;
    int count = 0;

    for (int x : adj_list[x])
    {
        count++;
    }

    cout << count;

    return 0;
}

// input:
// 7 7
// 0 1
// 1 2
// 2 3
// 1 3
// 4 0
// 0 5
// 5 6
// 1

// output:
// 3