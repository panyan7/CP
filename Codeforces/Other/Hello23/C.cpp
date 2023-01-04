#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    m--;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    ll res = 0;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    ll s = 0;
    priority_queue<ll> pq;
    for (int i = m; i > 0; i--) {
        s += a[i];
        if (a[i] > 0) {
            pq.push(a[i]);
        }
        while (s > 0) {
            ll x = pq.top();
            pq.pop();
            s -= x * 2;
            res++;
        }
    }
    s = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq2;
    for (int i = m+1; i < n; i++) {
        s += a[i];
        if (a[i] < 0) {
            pq2.push(a[i]);
        }
        while (s < 0) {
            ll x = pq2.top();
            pq2.pop();
            s -= x * 2;
            res++;
        }
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
