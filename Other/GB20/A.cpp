#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int t, n, x[55], s[55];

void solve() {
    if (n == 1) {
        cout << "0\n";
        return;
    }
    int res = 0;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (!s[x[j] - x[i]]) {
                s[x[j] - x[i]] = 1;
                ++res;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> x[i];
        solve();
    }
}
