#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<int> cnt(n+1, 0);
    for (auto p : mp)
        cnt[p.second]++;
    //vector<ll> pre_sum(n+1, 0);
    vector<ll> suf_cnt(n+1, 0);
    /*ll s = 0;
    for (int i = 1; i <= n; ++i) {
        pre_sum[i] = s;
        s += cnt[i] * i;
    }*/
    ll c = 0;
    for (int i = n; i >= 1; --i) {
        c += cnt[i];
        suf_cnt[i] = c;
    }
    ll res = INT64_MAX;
    for (int i = 1; i <= n; ++i) {
        res = min(res, n-suf_cnt[i]*i);
    }
    cout << res << "\n";
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
