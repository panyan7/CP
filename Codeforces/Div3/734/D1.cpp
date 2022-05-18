#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int t = 1, n, m, k;
 
void solve() {
    // check long long
    cin >> n >> m >> k;
    if (m % 2 == 1) {
        k = (m * n) / 2 - k;
        swap(m, n);
    }
    // only n can be odd
    bool can = true;
    int min_h = (n % 2) * (m / 2);
    if (k < min_h)
        can = false;
    if ((k - min_h) % 2 != 0)
        can = false;
    cout << (can ? "YES\n" : "NO\n");
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
