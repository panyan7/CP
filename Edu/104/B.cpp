#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    cin >> n >> k;
    --k;
    if (n % 2 == 0) {
        cout << (k % n) + 1 << "\n";
        return;
    }
    ll a = k / (n/2);
    ll r = k % (n/2);
    // cout << a << " " << r << " ";
    if (a % 2 == 0)
        cout << 1 + (((a / 2) + r)) % n << "\n";
    else
        cout << 1 + ((n/2)+1 + ((a/2) + r)) % n << "\n";
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
