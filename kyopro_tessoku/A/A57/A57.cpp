#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    long long N, Q;
    cin >> N >> Q;

    // 位置jからスタートしたときの2^i日後の位置を格納するdp
    vector<vector<long long>> dp(32, vector<long long>(100009, 0));

    for (int i = 1; i <= N; i++)
    {
        cin >> dp[0][i];
    }

    for (int i = 0; i < 31; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    // クエリに回答
    long long X, Y;
    for (int q = 0; q < Q; q++)
    {
        cin >> X >> Y;
        long long current_position = X;
        for (int i = 31; i >= 0; i--)
        {
            if (Y & (1 << i))
            {
                current_position = dp[i][current_position];
            }
        }
        cout << current_position << "\n";
    }

    cout << flush;
    return 0;
}