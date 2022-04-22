#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;
map<pll, ll> mp;
 
ll f(ll a, ll b) {
    // first number le a
    // second number le b
    if (a == -1 || b == -1)
        return 0;
    if (a == 0 || b == 0)
        return a + b + 1;
    if (a > b)
        swap(a, b);
    if (mp.find({a, b}) != mp.end())
        return mp[{a, b}];
    ll res = 0;
    ll first_bit = 0;
    for (int i = 30; i >= 0; i--) {
        if ((a & (1LL << i)) || (b & (1LL << i))) {
            first_bit = i;
            break;
        }
    }
    ll mask = (1LL << first_bit) - 1LL;
    res += f(min(a, mask), min(b, mask));
    if (a >= mask) {
        res += f(a - mask - 1, min(b, mask));
    }
    if (b >= mask) {
        res += f(b - mask - 1, min(a, mask));
    }
    mp[{a, b}] = res;
    return res;
}
 
// check long long
void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(r, r) - 2 * f(l-1, r) + f(l-1, l-1) << "\n";
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
