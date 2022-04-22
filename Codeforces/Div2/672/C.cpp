#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;
ll a[300005], local[300005];

void calc_local(int i) {
    if (i == 0 || i >= n+1)
        return;
    if (a[i] > a[i-1] && a[i] > a[i+1])
        local[i] = 1;
    if (a[i] < a[i-1] && a[i] < a[i+1])
        local[i] = -1;
}

// check long long
void solve() {
    cin >> n >> q;
    a[0] = -1e9, a[n+1] = -1e9;
    memset(local, 0, sizeof(local));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        calc_local(i);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += local[i] * a[i];
    cout << res << "\n";
    while (q--) {
        int l, r; cin >> l >> r;
        for (int i = l-1; i <= l+1; i++) {
            res -= local[i] * a[i];
            local[i] = 0;
        }
        for (int i = r-1; i <= r+1; i++) {
            res -= local[i] * a[i];
            local[i] = 0;
        }
        swap(a[l], a[r]);
        for (int i = l-1; i <= l+1; i++) {
            calc_local(i);
            res += local[i] * a[i];
        }
        for (int i = r-1; i <= r+1; i++) {
            if (local[i] != 0)
                continue;
            calc_local(i);
            res += local[i] * a[i];
        }
        cout << res << "\n";
    }
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
