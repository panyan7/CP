#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t, n, m, k;

void solve() {
    cin >> n;
    int a = 0, b = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        if (tmp == 1) { ++a; ++s; }
        else { ++b; s += 2; }
    }
    if (s % 2 == 1 || ((s/2) % 2 == 1 && a == 0))
        cout << "NO\n";
    else
        cout << "YES\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
