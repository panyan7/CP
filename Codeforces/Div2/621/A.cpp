#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = a[0];
    for (int i = 1; i < n; i++) {
        int cd = min(m, i*a[i]);
        m -= cd;
        res += cd / i;
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
