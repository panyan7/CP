#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n >> m;
    vector<ll> k (n, 0);
    for (auto& x : k) cin >> x;
    vector<ll> c (m, 0);
    ll res = 0;
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    sort(all(k));
    int j = 0;
    for (int i = 0; i < n; ++i) {
        res += c[k[i]-1];
    }
    ll save = 0;
    for (int i = n-1; i >= 0; ++j, --i) {
        if (c[k[i]-1] <= c[j]) {
            break;
        }
        save += (c[k[i]-1] - c[j]);
    }
    cout << res - save << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
