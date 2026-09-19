#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    bool match = true;
    for (int i = 0; i < n; i++)
    {
        if (t[i] != '*' && t[i] != s[i])
        {
            match = false;
        }
    }

    if (match)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}