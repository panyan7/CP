#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<ll> s(n);
    sort(a.begin(), a.end());
    ll sm = 0;
    for (int i = n-1; i >= 0; i--) {
        sm += a[i];
        s[i] = sm;
    }
    if (sm <= k) {
        cout << "0\n";
        return;
    }
    ll res = sm-k;
    for (int i = n-1; i >= 1; i--) {
        // set a[i..n-1] to a[0]
        ll r = (sm - s[i] + a[0] * (n-i) - k + n - i) / (n - i + 1);
        r = max(r, 0LL);
        //cout << r << " ";
        res = min(res, r+n-i);
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
