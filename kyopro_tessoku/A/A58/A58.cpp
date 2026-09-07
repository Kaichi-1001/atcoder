// セグメント木を実装する
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
            dat[i] = 0;
        }
    }
    // クエリ1を処理する関数
    void update(int pos, int x)
    {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2)
        {
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    // クエリ2を処理する関数
    // uは現在のセル番号、[a, b)はセルに対応する半開区間、[l, r)は求めたい半開区間
    // 半開区間[l, r)の最大値を求めるには、query(l, r, 1, siz + 1, 1)を呼び出せばよい
    int query(int l, int r, int a, int b, int u)
    {
        // 今のセルが含まれない場合
        if (r <= a || b <= l)
        {
            return -10000000;
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
        return max(AnswerL, AnswerR);
    }
};

int main()
{
    SegmentTree ST;
    int N, Q; 
    cin >> N >> Q;

    ST.init(N);

    int q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        if (q == 1) {
            int pos, x;
            cin >> pos >> x;
            ST.update(pos, x);
        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            cout << ST.query(l, r, 1, ST.siz + 1, 1) << "\n";
        }
    }

    cout << flush;
    return 0;
}