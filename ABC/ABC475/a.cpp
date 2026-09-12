#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string answer = "";

    for (int i = 0; i < n-1; i++)
    {
        answer += s[i];
        answer += 'o';
    }
    answer += s[n-1];
    
    cout << answer << endl;
}