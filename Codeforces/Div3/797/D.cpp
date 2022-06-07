#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n+1);
    for (int i = 0; i < n; i++)
        p[i+1] = p[i] + (s[i] == 'W' ? 1 : 0);
    int mn = INT_MAX;
    for (int i = k; i <= n; i++)
        mn = min(mn, p[i] - p[i-k]);
    cout << mn << "\n";
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
