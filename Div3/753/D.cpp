#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    string s;
    cin >> s;
    int nb = 0;
    vector<ll> b, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B')
            b.push_back(a[i]);
        else
            r.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(r.begin(), r.end());
    bool can = true;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < i+1)
            can = false;
    }
    for (int i = 0; i < r.size(); i++) {
        if (r[i] > (ll)b.size()+i+1)
            can = false;
    }
    cout << (can ? "YES\n" : "NO\n");
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
