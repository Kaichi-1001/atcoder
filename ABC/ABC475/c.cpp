#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, S, L;
    cin >> N >> S >> L;
    vector<long long> prefix(N + 1, 0);
    for (int i = 1; i < N; i++)
    {
        long long A;
        cin >> A;
        prefix[i + 1] = prefix[i] + A;
    }

    long long answer = 1;
    for (int left = 1; left <= S; left++)
    {
        for (int right = S; right <= N; right++)
        {
            long long left_distance = prefix[S] - prefix[left];
            long long right_distance = prefix[right] - prefix[S];
            long long cost = min(
                2 * left_distance + right_distance,
                left_distance + 2 * right_distance);

            if (cost <= L)
            {
                answer = max(answer, 1LL * (right - left + 1));
            }
        }
    }

    cout << answer << endl;
}