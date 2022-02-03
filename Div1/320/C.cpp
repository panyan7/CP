#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
const double eps = 1e-12;
 
// check long long
void solve() {
    cin >> n;
    vector<double> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto check = [&](double mid) {
        double c = 0.0, mx = 0.0;
        for (int i = 0; i < n; i++) {
            c += (double)a[i] - mid;
            mx = max(mx, c);
            c = max(c, 0.0);
        }
        c = 0.0;
        double mn = 0.0;
        for (int i = 0; i < n; i++) {
            c += (double)a[i] - mid;
            mn = min(mn, c);
            c = min(c, 0.0);
        }
        return -max(mx, -mn);
    };
    double lo = -1e4, hi = 1e4;
    while (lo + eps < hi) {
        double mid1 = lo + (hi - lo) / 3.0;
        double mid2 = hi - (hi - lo) / 3.0;
        if (check(mid1) <= check(mid2))
            lo = mid1;
        else
            hi = mid2;
    }
    cout << fixed << setprecision(10) << -check(lo) << "\n";
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

