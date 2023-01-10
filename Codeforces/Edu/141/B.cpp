#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<int> ans(n*n, 0);
    for (int i = 0; i < n*n; i += 2) {
        ans[i] = i / 2 + 1;
    }
    for (int i = 1; i < n*n; i += 2) {
        ans[i] = n*n-i/2;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = ans[k];
                k++;
            }
        } else {
            for (int j = n-1; j >= 0; j--) {
                a[i][j] = ans[k];
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
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
