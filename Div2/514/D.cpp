#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int cntn = 0, cntp = 0;
    for (int i = 0; i < n; i++) {
        if (y[i] > 0) 
            cntp++;
        else
            cntn++;
    }
    if (cntp > 0 && cntn > 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++)
        y[i] = abs(y[i]);
    ld lo = 0.2, hi = 1e15;
    auto check = [&](ld mid) {
        ld ub = 1e20, lb = -1e20;
        for (int i = 0; i < n; i++) {
            if (2*mid < (ld)y[i])
                return false;
            ld r = y[i] - mid;
            ld dx = sqrt(mid * mid - r * r);
            ub = min(ub, (ld)x[i] + dx);
            lb = max(lb, (ld)x[i] - dx);
        }
        return (ub >= lb);
    };
    for (int i = 0; i < 100; i++) {
        ld mid = (lo + hi) / 2.0;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(10) << (double)hi << "\n";
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
