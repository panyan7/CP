#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    ll hc, dc, hm, dm, w, a;
    cin >> hc >> dc >> hm >> dm;
    cin >> k >> w >> a;
    for (int i = 0; i <= k; i++) {
        ll hc_new = hc + i * a;
        ll dc_new = dc + (k-i) * w;
        if ((hm + dc_new - 1) / dc_new <= (hc_new + dm - 1) / dm) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
