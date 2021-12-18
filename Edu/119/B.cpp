#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll w, h;
    cin >> w >> h;
    ll res = 0;
    for (int j = 0; j < 4; j++) {
        cin >> k;
        vector<ll> l(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        ll md = l[k-1] - l[0];
        if (j < 2)
            res = max(res, md * h);
        else
            res = max(res, md * w);
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
