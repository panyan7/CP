#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

void solve() {
    int w, h;
    cin >> w >> h >> n;
    int a = 1, b = 1;
    while (w % 2 == 0) {
        w /= 2;
        a *= 2;
    }
    while (h % 2 == 0) {
        h /= 2; b *= 2;
    }
    if (a * b >= n) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
