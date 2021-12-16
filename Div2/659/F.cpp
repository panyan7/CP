#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a (n, vector<int> (m, 0));
    vector<int> r (n, 0), c (n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            r[i] = max(r[i], a[i][j]);
            c[j] = max(c[j], a[i][j]);
        }
    }
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
