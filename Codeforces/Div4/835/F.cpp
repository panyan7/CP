#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    ll c, d;
    cin >> c >> d;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    vector<ll> p(n+1);
    for (int i = 0; i < n; i++)
        p[i+1] = p[i] + a[i];
    if (d <= n && p[d] >= c) {
        cout << "Infinity\n";
        return;
    }
    if (d > n && p[n] >= c) {
        cout << "Infinity\n";
        return;
    }
    ll lo = n-1, hi = d;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2LL;
        ll f = d / mid;
        ll total = f * p[n] + p[min(d - f * mid, (ll)n)];
        if (total >= c)
            lo = mid;
        else
            hi = mid;
    }
    if (lo >= n) {
        cout << lo-1 << "\n";
        return;
    }
    for (int k = n; k >= 1; k--) {
        ll f = d / k;
        ll total = f * p[k] + p[d - f * k];
        if (total >= c) {
            cout << k-1 << "\n";
            return;
        }
    }
    cout << "Impossible\n";
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
