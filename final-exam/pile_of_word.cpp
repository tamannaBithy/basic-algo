#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
            cout << "NO" << endl;
        else
        {
            int freq[26] = {0};

            for (char c : s1)
                freq[c - 'a']++;

            for (char c2 : s2)
                freq[c2 - 'a']--;

            bool result = true;

            for (int i = 0; i < 26; i++)
                if (freq[i] != 0)
                {
                    result = false;
                    break;
                }

            if (result)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}