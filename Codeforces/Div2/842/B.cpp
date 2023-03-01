#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    int t = 1;
    for (int i = 0; i < n; i++)
        if (p[i] == t)
            t++;
    cout << ((n-t+1)+k-1) / k << "\n";
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
