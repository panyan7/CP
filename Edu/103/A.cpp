#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n >> k;
    if (k >= n)
        cout << (k/n) + (k % n == 0 ? 0 : 1) << "\n";
    else
        cout << (n % k == 0 ? 1 : 2) << "\n";
    
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
