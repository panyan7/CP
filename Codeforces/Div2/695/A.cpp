#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "9" << "\n";
        return;
    }
    cout << "98";
    if (n == 2) {
        cout << "\n";
        return;
    }
    int d = 9;
    for (int i = 2; i < n; ++i) {
        cout << d;
        ++d;
        if (d == 10) d = 0;
    }
    cout << "\n";
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
