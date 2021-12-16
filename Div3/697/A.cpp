#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(c) (c).begin(), (c).end()

long long t = 1, n, m, k;

void solve() {
    cin >> n;
    while (n > 1) {
        if (n % 2 == 1) {
            cout << "YES\n";
            return;
        }
        n /= 2;
    }
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
