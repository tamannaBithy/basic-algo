#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

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
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;
    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        cout << leaderA << " " << leaderB << endl;

        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "cycle detected";
    else
        cout << "no cycle";
    return 0;
}

// input for cycle :

// 6 6
// 0 1
// 1 2
// 0 4
// 4 5
// 5 3
// 3 4

// input for no cycle :

// 6 5
// 0 1
// 1 2
// 0 4
// 4 5
// 3 4