#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    ll c;
    cin >> n >> c;
    vector<ll> a(n);
    vector<ll> b(n-1);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    ll min_days = 3e14;
    ll cur_days = 0;
    ll cur_tug = 0;
    for (int i = 0; i < n-1; i++) {
        // go to next quickly
        min_days = min(min_days, cur_days + (c - cur_tug + a[i] - 1) / a[i]);
        ll days_need = (b[i] - cur_tug + a[i] - 1) / a[i];
        cur_tug += days_need * a[i] - b[i];
        cur_days += days_need + 1;
    }
    min_days = min(min_days, cur_days + (c - cur_tug + a[n-1] - 1) / a[n-1]);
    cout << min_days << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
