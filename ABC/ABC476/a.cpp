#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    int n = s.size();

    if (s[n - 1] == 'e')
    {
        t = s + 'r';
    }
    else
    {
        t = s + "er";
    }

    cout << t << endl;
}