#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n, 0), b (n, 0);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    map<int, int> mp;
    for (int i = -1; i <= 1; ++i)
        mp[i] = n;
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]] == n) mp[a[i]]=i+1;
    }
    for (int i = n-1; i >= 0; --i) {
        if (a[i] > b[i] && mp[-1] > i) {
            cout << "NO\n";
            return;
        }
        if (a[i] < b[i] && mp[1] > i) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
