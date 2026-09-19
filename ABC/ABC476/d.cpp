#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    vector<long long> A(n), B(m);
    for (long long &price : A)
    {
        cin >> price;
    }
    for (long long &price : B)
    {
        cin >> price;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> dessert_sum(n + 1), drink_sum(m + 1);
    vector<long long> drink_k_bill_sum(m + 1);

    for (long long i = 0; i < n; i++)
    {
        dessert_sum[i + 1] = dessert_sum[i] + A[i];
    }
    for (long long j = 0; j < m; j++)
    {
        drink_sum[j + 1] = drink_sum[j] + B[j];
        drink_k_bill_sum[j + 1] =
            drink_k_bill_sum[j] + (B[j] + k - 1) / k;
    }

    const long long total_money = x + k * y;
    long long answer = 0;

    for (long long drink_count = 0; drink_count <= m; drink_count++)
    {
        if (drink_k_bill_sum[drink_count] > y ||
            drink_sum[drink_count] > total_money)
        {
            break;
        }

        const long long remaining_money =
            total_money - drink_sum[drink_count];
        const long long dessert_count =
            upper_bound(dessert_sum.begin(), dessert_sum.end(),
                        remaining_money) -
            dessert_sum.begin() - 1;
        answer = max(answer, drink_count + dessert_count);
    }

    cout << answer << '\n';
    return 0;
}