#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    string s;
    cin >> s;
    n = s.size();
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            a = a * 10 + (s[i] - '0');
        else
            b = b * 10 + (s[i] - '0');
    }
    cout << (a + 1) * (b + 1) - 2 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
