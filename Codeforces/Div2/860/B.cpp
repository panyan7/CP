#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    set<int> st;
    vector<int> res(n);
    for (int i = n-1; i >= 0; i--) {
        int winner = -1;
        for (int x : a[i]) {
            if (st.count(x) == 0)
                winner = x;
        }
        if (winner == -1) {
            cout << "-1\n";
            return;
        }
        res[i] = winner;
        for (int x : a[i])
            st.insert(x);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
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
