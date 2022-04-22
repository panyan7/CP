#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n, 0);
    vector<int> b (n, 0);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int l = 0, r = n-1;
    while (l < n && a[l] == b[l]) ++l;
    while (r >= 0 && a[r] == b[r]) --r;
    if (l == n) {
        cout << "YES\n";
        return;
    }
    int k = b[l]-a[l];
    if (k < 0) {
        cout << "NO\n";
        return;
    }
    for (int i = l; i <= r; ++i) {
        if (b[i]-a[i] != k) {
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
