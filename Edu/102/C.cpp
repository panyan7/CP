#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m, k;

void solve() {
    cin >> n >> k;
    for (int i = 1; i < 2*k-n; ++i) {
        cout << i << " ";
    }
    for (int i = 2*k-n; i <= k; ++i) {
        cout << (3*k-n)-i << " ";
    }
    cout << "\n";
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
