#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<ll> b(a);
    vector<ll> ps(n, 0);
    sort(b.begin(), b.end());
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        s += b[i];
        ps[i] = s;
    }
    int lo = 0, hi = b.size()-1;
    /*
    bool can = true;
    ll token = ps[0];
    for (int i = 1; i < n; ++i) {
        if (token < b[i]) {
            can = false;
            break;
        }
    }
    if (can) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << "\n";
    }
    */
    while (lo+1 < hi) {
        int mid = lo + (hi-lo)/2;
        bool can = true;
        ll token = ps[mid];
        for (int i = mid+1; i < n; ++i) {
            if (token < b[i]) {
                can = false;
                break;
            }
            token += b[i];
        }
        if (can) hi = mid;
        else lo = mid;
    }
    vector<ll> res;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= b[hi])
            res.push_back(i+1);
    }
    cout << res.size() << "\n";
    for (ll x : res)
        cout << x << " ";
    cout << "\n";
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
