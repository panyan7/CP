#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (auto& x : c) cin >> x;
    map<int,vector<int>> mp;
    bool lst = false;
    int lstid = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i] != a[i])
            mp[b[i]].push_back(i);
        if (b[i] == c[m-1]) {
            lst = true;
            lstid = i+1;
        }
    }
    if (!lst) {
        cout << "NO\n";
        return;
    }
    vector<int> res;
    for (int i = m-1; i >= 0; --i) {
        if (mp[c[i]].size() > 0) {
            res.push_back(mp[c[i]].back()+1);
            if (i == m-1)
                lstid = mp[c[i]].back()+1;
            mp[c[i]].pop_back();
        } else {
            res.push_back(lstid);
        }
    }
    bool can = true;
    for (auto& p : mp) {
        if (p.second.size() != 0)
            can = false;
    }
    if (can) {
        cout << "YES\n";
        for (int i = m-1; i >= 0; --i)
            cout << res[i] << (i == 0 ? "\n" : " ");
    }
    else
        cout << "NO\n";
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
