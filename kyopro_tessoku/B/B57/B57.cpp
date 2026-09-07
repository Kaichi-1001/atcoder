#include <bits/stdc++.h>
using namespace std;

long long substract_digits(long long x)
{
    long long sum = 0;
    int wari = 1;
    for (int i = 0; i < 6; i++)
    {
        sum += (x / wari) % 10;
        wari *= 10;
    }
    return x - sum;
}

int main()
{
    // input
    long long N, K;
    cin >> N >> K;

    // 整数jに対して「各位の数字の和を引く」を2^i回繰り返した後の整数をdp[i][j]に格納する
    vector<vector<long long>> dp(32, vector<long long>(300009, 0));
    for (int j = 1; j <= N; j++)
    {
        dp[0][j] = substract_digits(j);
    }

    // dpの前計算
    for (int i = 0; i < 31; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    // 処理
    for (int x = 1; x <= N; x++)
    {
        long long current_number = x;
        for (int k = 31; k >= 0; k--)
        {
            if (K & (1LL << k))
            {
                current_number = dp[k][current_number];
            }
        }
        cout << current_number << "\n";
    }

    cout << flush;
    return 0;
}