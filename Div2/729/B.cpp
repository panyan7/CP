#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1;

void solve() {
    // check long long
    ll a, b, n;
    cin >> n >> a >> b;
    if (n == 1) {
        cout << "Yes\n";
        return;
    }
    ll c = 1;
    while (c <= n) {
        if ((n - c) % b == 0) {
            cout << "Yes\n";
            return;
        }
        c *= a;
        if (c == 1)
            break;
    }
    cout << "No\n";
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
