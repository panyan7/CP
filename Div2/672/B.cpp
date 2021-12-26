#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll cnt[32];

// check long long
void solve() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cnt[(ll)floor(log2(x))]++;
    }
    ll res = 0;
    for (int i = 0; i < 32; i++) {
        res += cnt[i] * (cnt[i] - 1) / 2;
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
