#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll f[46];

bool check(ll x, ll y, int n) {
    if (n == 0)
        return true;
    if (y >= f[n])
        return check(y - f[n], x, n-1);
    if (f[n+1] - y - 1 >= f[n])
        return check(y, x, n-1);
    return false;
}

void solve() {
    ll x, y;
    cin >> n >> x >> y;
    x--, y--;
    cout << (check(x,y,n) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 45; i++)
        f[i] = f[i-1] + f[i-2];
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
