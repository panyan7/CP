#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    ll k = 1;
    m = 2*n;
    while (m % 2 == 0) {
        m /= 2;
        k *= 2;
    }
    //cout << k << " ";
    ll l = 2*n/k + 1 - k;
    cout << l/2 << " " << l/2+k-1 << "\n";
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
