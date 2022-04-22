#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
const string moves = "RUD";

// check long long
void solve() {
    cin >> n >> m >> k;
    if (k > 4*n*m - 2*n - 2*m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<pair<ll,string>> res;
    if (m == 1) {
        ll t = min(k, n-1);
        if (t > 0) {
            res.push_back({t, "D"});
        }
        k -= t;
        t = min(k, n-1);
        if (t > 0) {
            res.push_back({t, "U"});
        }
        cout << res.size() << "\n";
        for (auto p : res) {
            cout << p.first << " " << p.second << "\n";
        }
        return;
    }
    if (k > 0) {
        ll t = min(k, m-1);
        if (t > 0)
            res.push_back({t, "R"});
        k -= t;
    }
    if (k > 0) {
        ll t = min(k, m-1);
        if (t > 0)
            res.push_back({t, "L"});
        k -= t;
    }
    for (int i = 0; i < n-1; i++) {
        if (k == 0)
            break;
        if (k > 0) {
            res.push_back({1, "D"});
            k--;
        }
        if (k > 0) {
            ll t = min(k/3, m-1);
            k -= 3*t;
            if (t > 0)
                res.push_back({t, "RUD"});
            if (t < m-1 && k > 0 && k <= 2) {
                res.push_back({1, moves.substr(0, k)});
                k = 0;
            }
        }
        if (k > 0) {
            ll t = min(k, m-1);
            if (t > 0)
                res.push_back({t, "L"});
            k -= t;
        }
    }
    if (k > 0) {
        res.push_back({k, "U"});
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first << " " << p.second << "\n";
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
