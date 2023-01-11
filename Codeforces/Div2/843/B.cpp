#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
const int N = 2 * 1e5 + 10;
int s[N];

void solve() {
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            s[a[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int x : a[i]) {
            if (s[x] == 1)
                ok = false;
        }
        if (ok) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                for (int x : a[i]) {
                    s[x] = 0;
                }
            }
            return;
        }
    }
    cout << "No\n";
    for (int i = 0; i < n; i++) {
        for (int x : a[i]) {
            s[x] = 0;
        }
    }
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
