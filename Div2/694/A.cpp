#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(), (c).end()

ll t, n, m, x;

void solve() {
    cin >> n >> x;
    ll s = 0, y = 0;
    vector<int> a (n, 0);
    for (auto& b : a) {
        cin >> b;
        y += (b+x-1)/x;
        s += b;
    }
    cout << (s+x-1)/x << " " << y << "\n";
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
