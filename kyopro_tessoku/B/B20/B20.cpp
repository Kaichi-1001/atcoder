#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, dp[2009][2009];

int main()
{
    cin >> s;
    n = s.size();
    cin >> t;
    m = t.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 斜めは置換、右は削除、下は挿入に対応している
            if (i >= 1 && j >= 1 && s[i - 1] != t[j - 1])
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            else if (i >= 1 && j >= 1)
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            else if (i >= 1)
                dp[i][j] = dp[i - 1][j] + 1;
            else if (j >= 1)
                dp[i][j] = dp[i][j - 1] + 1;
        }
    }
    cout << dp[n][m] << endl;
}