#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int t, n, x[100005];

void solve() {
    int d = 1;
    for (int i = 2; i <= n; ++i) {
        if (x[i] == x[i-1]) {
            ++x[i];
            ++d;
        } else if (x[i] > x[i-1]) {
            ++d;
        } else {
            ++x[i];
        }
    }
    cout << d << "\n";
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
