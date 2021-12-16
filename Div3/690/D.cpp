#include <bits/stdc++.h>
using namespace std;

int t, n, s[10005], a[10005];

void solve() {
    int sm = s[n];
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        for (auto p : m) {
            if (s[i] % p.first == 0)
                ++m[p.first];
        }
        if (sm % s[i] == 0) {
            ++m[s[i]];
        }
    }
    for (auto p : m) {
        if (p.first * p.second == sm) {
            cout << n-p.second << "\n";
            return;
        }
    }
    cout << n-1 << "\n";
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }
        solve();
    }
}
