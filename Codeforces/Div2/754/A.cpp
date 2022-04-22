#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = 2;
    res = min(abs(a*2-b-c)%3, res);
    res = min(abs(b*2-a-c)%3, res);
    res = min(abs(c*2-b-a)%3, res);
    cout << res << "\n";
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
