#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    map<int,int> mp;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++mp[x];
        res = max(res, mp[x]);
    }
    cout << res << "\n";
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
