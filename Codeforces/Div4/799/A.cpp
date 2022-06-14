#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if (b > a)
        res++;
    if (c > a)
        res++;
    if (d > a)
        res++;
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
