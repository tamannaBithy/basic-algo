#include <bits/stdc++.h>
using namespace std;

class Edge
{

public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
int n, e;
vector<long long> dis;

void bellman_ford(int t)
{
    for (int i = 1; i <= n - 1; i++)
    {
        bool updated = false;
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
}

int main()
{

    cin >> n >> e;
    edge_list.clear();

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    dis.assign(n + 1, LLONG_MAX);

    int s, t;
    cin >> s >> t;

    dis[s] = 0;

    bellman_ford(t);
    return 0;
}