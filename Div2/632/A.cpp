#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n-1; ++i) {
        cout << "WB" << string(m-2, 'B') << "\n";
    }
    cout << "BB" << string(m-2, 'B') << "\n";
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
