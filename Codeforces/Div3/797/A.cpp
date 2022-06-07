#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    int h1 = (n - 6 + 2) / 3 + 3;
    int h2 = (n - 6 + 1) / 3 + 2;
    int h3 = (n - 6) / 3 + 1;
    cout << h2 << " " << h1 << " " << h3 << "\n";
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
