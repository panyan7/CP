#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    // check long long
    cin >> n;
    ll a, b;
    if (n % 3 == 0) {
        a = n/3;
        b = n/3;
    } else if (n % 3 == 1) {
        a = n/3+1;
        b = n/3;
    } else {
        a = n/3;
        b = n/3+1;
    }
    cout << a << " " << b << "\n";
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
