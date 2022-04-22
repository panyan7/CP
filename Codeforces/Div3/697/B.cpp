#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(c) (c).begin(), (c).end()

int t = 1, n, m, k;

void solve() {
    cin >> n;
    k = n / 2020;
    int r = n % 2020;
    if (r <= k)
        cout << "YES\n";
    else
        cout << "NO\n";
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
