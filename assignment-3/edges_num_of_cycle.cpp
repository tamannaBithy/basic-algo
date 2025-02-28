#include <bits/stdc++.h>
using namespace std;
vector<long long> par;
vector<long long> group_size;

int find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    par.assign(n + 1, -1);
    group_size.assign(n + 1, 1);

    int count = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            count++;
        }

        else
            dsu_union(a, b);
    }

    cout << count;

    return 0;
}

// input:
// 3 3
// 1 2
// 2 3
// 1 3

// output:
// 1

// input:
// 5 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3

// output:
// 3