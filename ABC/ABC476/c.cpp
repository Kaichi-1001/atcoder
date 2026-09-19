#include <bits/stdc++.h>
using namespace std;

// 4番目以降はどうでもいいから、降順3番目までを編集する関数
void top_3(long long x, long long P[3]) {
    if (x >= P[0]) {
        P[2] = P[1];
        P[1] = P[0];
        P[0] = x;
    } else if (x < P[0] && x >= P[1]) {
        P[2] = P[1];
        P[1] = x;
    } else if (x < P[1] && x >= P[2]) {
        P[2] = x;
    }

    cout << P[2] << "\n";
}

int main() {
    // input
    int n;
    cin >> n;

    long long A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long P[3];
    if (A[0] >= A[1]) {
        P[0] = A[0];
        P[1] = A[1];
    } else {
        P[0] = A[1];
        P[1] = A[0];
    }
    P[2] = 0;

    for (int i = 2; i < n; i++) {
        long long x = A[i];
        top_3(x, P);
    }

    cout << flush;
    return 0;
}