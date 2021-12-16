#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

void solve() {
    vector<ll> x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        x.push_back(p);
    }
    sort(x.begin(), x.end());
    ll a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0 && x[n-i-1] % 2 == 0)
            a += x[n-i-1];
        if (i % 2 == 1 && x[n-i-1] % 2 == 1)
            b += x[n-i-1];
    }
    if (a > b)
        cout << "Alice\n";
    else if (a == b)
        cout << "Tie\n";
    else
        cout << "Bob\n";
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
