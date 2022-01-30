#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    k = floor(log2(n));
    k = 1 << k;
    if (k == n)
        k >>= 1;
    for (int i = 1; i < n; i++) {
        if (i < k)
            cout << i << " ";
    }
    cout << 0 << " ";
    for (int i = 1; i < n; i++) {
        if (i >= k)
            cout << i << " ";
    }
    cout << "\n";
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
