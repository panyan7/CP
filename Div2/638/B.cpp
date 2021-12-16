#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve() {
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        s.insert(a);
    }
    if (s.size() > k) {
        cout << "-1\n";
        return;
    }
    cout << n * k << "\n";
    for (int i = 0; i < n; ++i) {
        for (int b : s) cout << b << " ";
        for (int j = 0; j < k - int(s.size()); ++j) {
            cout << "1 ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        solve();
    }
    return 0;
}
