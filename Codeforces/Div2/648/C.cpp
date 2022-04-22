#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    vector<pii> pos(n+1);
    for (int i = 0; i < n; i++) {
        pos[a[i]].first = i;
        pos[b[i]].second = i;
    }
    vector<int> cnt(n, 0);
    for (int i = 1; i <= n; i++) {
        cnt[(pos[i].second - pos[i].first + n) % n]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, cnt[i]);
    cout << res << "\n";
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
