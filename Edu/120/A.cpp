#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l2 > l1)
        swap(l2, l1);
    if (l3 > l1)
        swap(l3, l1);
    if ((l1 == l2 && l3 % 2 == 0) || (l2 == l3 && l1 % 2 == 0) || (l1 == l3 && l2 % 2 == 0))
        cout << "YES\n";
    else if (l1 == l2 + l3)
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
