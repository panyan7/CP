#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    m = a + b + c - m - 1;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
    assert(a >= b && b >= c);
    // a > b > c
    ll mn = 2;
    ll mx = min(a-1, b+c) * 2 + max(b+c-a+1, 0LL);
    if (mn <= m && m <= mx)
        cout << "YES\n";
    else
        cout << "NO\n";
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
