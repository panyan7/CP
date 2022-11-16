#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n >> q;
    vector<ll> a(n), p(n+1), s(n+1);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
        p[i+1] = p[i] ^ a[i];
    for (int i = 0; i < n; i++)
        s[i+1] = s[i] + a[i];
    map<ll,array<set<int>,2>> mp;
    mp[0][0].insert(0);
    for (int i = 1; i <= n; i++) {
        mp[p[i]][i%2].insert(i);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if ((p[r] ^ p[l-1]) != 0)
            cout << "-1\n";
        else if (s[r] - s[l-1] == 0)
            cout << "0\n";
        else if ((r-l+1) % 2 == 1)
            cout << "1\n";
        else if (a[l-1] == 0 || a[r-1] == 0)
            cout << "1\n";
        else {
            auto it = mp[p[l-1]][l%2].upper_bound(l-1);
            if (it != mp[p[l-1]][l%2].end() && *it <= r)
                cout << "2\n";
            else
                cout << "-1\n";
        }
    }
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
