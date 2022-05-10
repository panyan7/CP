#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ll res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll d = 0;
            for (int k = 0; k < m; k++) {
                d += abs((int)s[i][k] - s[j][k]);
            }
            res = min(res, d);
        }
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
