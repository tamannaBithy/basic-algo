#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2)
        return n;
    return fibo(n - 1) + fibo(n - 2); // O(2^n)
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}

/// ai recursioner time complexity O(2^n) ja khub baje. 40/45 er fibonacci ber korte gelei TLE ase. er theke boro numberer fibonacci konovabei ai recursion diye kora somvob na that's why we need to optimize it.