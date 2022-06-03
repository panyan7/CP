#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    string s(m, '0');
    vector<pll> l;
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        cout << "? " << s << "\n";
        cout.flush();
        ll x;
        cin >> x;
        l.push_back({x, i});
        s[i] = '0';
    }
    sort(l.begin(), l.end());
    ll res = 0;
    for (int i = 0; i < m; i++) {
        s[l[i].second] = '1';
        cout << "? " << s << "\n";
        cout.flush();
        ll x;
        cin >> x;
        if (x - res == l[i].first) {
            // connects two vertices, in MST
            res = x;
        } else {
            s[l[i].second] = '0';
        }
    }
    cout << "! " << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
