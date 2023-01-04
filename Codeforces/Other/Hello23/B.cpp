#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << (i % 2 == 0 ? -1 : 1) << " ";
        }
        cout << "\n";
    } else {
        if (n == 3) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        // (n-1) / 2 * s + x = s
        // (n-3) / 2 * s = -x
        // s = 1, x = -(n-3)/2, (n-3)/2+1
        for (int i = 0; i < n; i++) {
            cout << (i % 2 == 0 ? -(n-3)/2 : (n-3)/2+1) << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
