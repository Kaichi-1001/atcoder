#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int dat[300009], siz = 1;

    // 要素datの初期化をする関数
    void init(int N)
    {
        siz = 1;
        while (siz < N)
        {
            siz *= 2;
        }
        for (int i = 1; i <= 2 * siz; i++)
        {
            dat[i] = 1000009;
        }
    }

    // pos番目の要素をxに更新する関数
    void update(int pos, int x)
    {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2)
        {
            pos /= 2;
            dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    // uは現在のセル番号、[a, b)はセルに対応する半開区間、[l, r)は求めたい半開区間
    // 半開区間[l, r)の最小値を求めるには、query(l, r, 1, siz + 1, 1)を呼び出せばよい
    int query(int l, int r, int a, int b, int u)
    {
        // 今のセルが含まれない場合
        if (r <= a || b <= l)
        {
            return 10000000;
        }
        // 今のセルが完全に含まれる場合
        if (l <= a && b <= r)
        {
            return dat[u];
        }
        // 今のセルが部分的に含まれる場合 -> 分解する必要がある
        int m = (a + b) / 2;
        int AnswerL = query(l, r, a, m, 2 * u);
        int AnswerR = query(l, r, m, b, 2 * u + 1);
        return min(AnswerL, AnswerR);
    }
};
int main()
{
    // input
    int N;
    long long X[100009], L, R;
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i];
    }

    // セグメント木を使ったDP
    SegmentTree ST;
    ST.init(N);
    ST.update(1, 0);
    int dp[100009];
    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        int posL = lower_bound(X + 1, X + N + 1, X[i] - R) - X;
        int posR = lower_bound(X + 1, X + N + 1, X[i] - L + 1) - X - 1;
        dp[i] = ST.query(posL, posR + 1, 1, ST.siz + 1, 1) + 1;
        ST.update(i, dp[i]);
    }

    // answer
    cout << dp[N] << endl;
    return 0;
}