#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    ll p;
    cin >> n >> p;
    ll l, r;
    double res = 0.0;
    vector<double> prob_good(n);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        ll r1 = r / p;
        ll l1 = (l + p - 1) / p;
        ll ok = (r1 - l1 + 1);
        prob_good[i] = (double)(ok) / (double)(r - l + 1);
    }
    for (int i = 0; i < n; i++) {
        res += 1.0 - (1.0 - prob_good[i]) * (1.0 - prob_good[(i+1)%n]);
    }
    cout << fixed << setprecision(10) << res * 2000 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
