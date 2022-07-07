#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    ll res = n * (n + 1) / 2;
    for (int i = 0; i+1 < n; i++) {
        if (s[i] == s[i+1])
            res -= (i+1);
    }
    cout << res << "\n";
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
