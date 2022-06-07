#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    ll mx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] - b[i] >= 0 && b[i] > 0)
            mx = max(mx, a[i] - b[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] - b[i] < 0) {
            ok = false;
        } else {
            if (b[i] == 0 && mx != -1 && a[i] - b[i] > mx)
                ok = false;
            if (b[i] > 0 && mx != -1 && a[i] - b[i] != mx)
                ok = false;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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
