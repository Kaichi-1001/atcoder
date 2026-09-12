#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(1009, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int num_1yen = 0;
    int num_10yen = 0;
    int num_100yen = 0;
    for (int i = 1; i <= n; i++)
    {
        int num_bill = A[i] / 1000 + 1;
        int change = 1000 * num_bill - A[i];
        num_1yen += change % 10;
        change /= 10;
        num_10yen += change % 10;
        change /= 10;
        num_100yen += change % 10;
    }

    cout << num_1yen << " " << num_10yen << " " << num_100yen << endl;
}