#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<vector<ll>> a(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        for (int j = 0; j < c; j++) {
            ll x; cin >> x;
            a[i].push_back(x);
        }
    }
    cin >> m;
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            cout << a[i].size() << " \n"[i+1==n];
        }
        return;
    }
    set<array<int,10>> s;
    for (int i = 0; i < m; i++) {
        array<int,10> b = {};
        for (int j = 0; j < n; j++) {
            cin >> b[j]; b[j]--;
        }
        s.insert(b);
    }
    ll res = 0LL;
    array<int,10> sol = {};
    array<int,10> best = {};
    for (int i = 0; i < n; i++) {
        best[i] = a[i].size()-1;
    }
    if (s.find(best) == s.end()) {
        for (int i = 0; i < n; i++) {
            cout << best[i]+1 << " \n"[i+1==n];
        }
        return;
    }
    for (auto b : s) {
        ll r = 0LL;
        for (int i = 0; i < n; i++) {
            r += a[i][b[i]];
        }
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                array<int,10> c = b;
                c[i]--;
                if (s.find(c) == s.end()) {
                    if (r - a[i][b[i]] + a[i][c[i]] > res) {
                        res = r - a[i][b[i]] + a[i][c[i]];
                        sol = c;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sol[i]+1 << " \n"[i+1==n];
    }
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
