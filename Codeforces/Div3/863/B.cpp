#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    cin >> n;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d1 = min({x1-1, n-x1, y1-1, n-y1});
    ll d2 = min({x2-1, n-x2, y2-1, n-y2});
    cout << abs(d1-d2) << "\n";
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
