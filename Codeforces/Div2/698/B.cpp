#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;
const int MAXN = 1e9+1;

void solve() {
    int q, d;
    cin >> q >> d;
    vector<int> md (d, INT_MAX);
    for (int i = 0; i < 10; ++i) {
        int nm = i*10+d;
        md[nm % d] = min(nm, md[nm % d]);
    }
    for (int i = 0; i < 10; ++i) {
        int nm = d*10+i;
        md[nm % d] = min(nm, md[nm % d]);
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        if (x >= md[x % d]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
