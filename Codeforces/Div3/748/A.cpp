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
    cout << max(0LL,max(b,c)-a+1) << " " << max(0LL,max(a,c)-b+1) << " " << max(0LL,max(a,b)-c+1) << "\n";
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
