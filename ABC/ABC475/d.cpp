#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<bool> is_prime(10000000, true);
vector<int> a(26, -1);
vector<bool> used(10, false);
int answer = -1;

void dfs(int index, int value)
{
    if (answer != -1)
    {
        return;
    }
    if (index == n)
    {
        if (is_prime[value])
        {
            answer = value;
        }
        return;
    }

    int c = s[index] - 'a';
    if (a[c] != -1)
    {
        dfs(index + 1, value * 10 + a[c]);
        return;
    }

    for (int d = 0; d <= 9; d++)
    {
        if (used[d] || (index == 0 && d == 0))
        {
            continue;
        }
        a[c] = d;
        used[d] = true;
        dfs(index + 1, value * 10 + d);
        used[d] = false;
        a[c] = -1;
    }
}

int main()
{
    cin >> s;

    n = s.size();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 10000000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < 10000000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    dfs(0, 0);
    cout << answer << endl;
}