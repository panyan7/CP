#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    n = a.size();
    bool can = true;
    for (int i = 0; i < n; i++)
        if (a[i] != c[i] && b[i] != c[i])
            can = false;
    cout << (can ? "YES\n" : "NO\n");
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
