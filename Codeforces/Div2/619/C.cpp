#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    ll k = (n-m) / (m+1), r = (n-m) % (m+1);
    // divide into m+1 subarray
    // r of them are k+1, m+1-r of them k
    ll res = r * (k+2) * (k+1) / 2 + (m+1-r) * (k+1) * k / 2;
    cout << (n+1)*n/2 - res << "\n";
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
