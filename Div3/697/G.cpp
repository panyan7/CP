#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(c) (c).begin(), (c).end()

int t = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a (n, 0);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        ++mp[a[i]];
        if (a[i] != 1)
            mp[a[i]] = max(mp[a[i]], mp[1]+1);
        for (int j = 2; j <= sqrt(a[i]); ++j) {
            if (a[i] % j == 0) {
                mp[a[i]] = max(mp[a[i]], mp[a[i]/j]+1);
                mp[a[i]] = max(mp[a[i]], mp[j]+1);
            }
        }
    }
    int res = 0;
    for (auto p : mp) {
        res = max(res, p.second);
    }
    cout << n-res << "\n";
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
