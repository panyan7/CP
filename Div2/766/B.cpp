#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    int base_r = (n % 2) ? 1 : 2;
    int base_c = (m % 2) ? 1 : 2;
    int res = (n/2) + (m/2);
    vector<int> dist;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int d = max(i+j, n-1-i+m-1-j);
            d = max(d, i+m-1-j);
            d = max(d, j+n-1-i);
            dist.push_back(d);
        }
    }
    sort(dist.begin(), dist.end());
    for (int k = 0; k < n*m; k++) {
        cout << dist[k] << " ";
    }
    cout << "\n";
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
