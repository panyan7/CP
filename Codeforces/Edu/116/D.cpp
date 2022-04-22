#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m+1, 0));
    vector<vector<int>> mxl(n, vector<int>(m, 0));
    vector<vector<int>> mxr(n, vector<int>(m, 0));
    vector<vector<int>> mnl(n, vector<int>(m, 0));
    vector<vector<int>> mnr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        a[i][m] = i;
    }
    //sort(a.begin(), a.end(), [&](vector<int>& a, vector<int>& b) { return a[0] > b[0]; });
    sort(a.begin(), a.end(), greater<vector<int>>());
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
            mx = max(mx, a[i][j]);
            mxl[i][j] = mx;
        }
        mx = 0;
        for (int j = m-1; j >= 0; j--) {
            mx = max(mx, a[i][j]);
            mxr[i][j] = mx;
        }
        int mn = INT_MAX;
        for (int j = 0; j < m; j++) {
            mn = min(mn, a[i][j]);
            mnl[i][j] = mn;
        }
        mn = INT_MAX;
        for (int j = m-1; j >= 0; j--) {
            mn = min(mn, a[i][j]);
            mnr[i][j] = mn;
        }
    }
    for (int j = 1; j < m; j++) {
        vector<int> mxxl(n), mnnl(n);
        vector<int> mxxr(n), mnnr(n);
        int mx = 0, mn = INT_MAX;
        for (int i = n-1; i >= 0; i--) {
            mx = max(mx, mxl[i][j-1]);
            mxxl[i] = mx;
        }
        for (int i = 0; i < n; i++) {
            mn = min(mn, mnl[i][j-1]);
            mnnl[i] = mn;
        }
        mx = 0, mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mx = max(mx, mxr[i][j]);
            mxxr[i] = mx;
        }
        for (int i = n-1; i >= 0; i--) {
            mn = min(mn, mnr[i][j]);
            mnnr[i] = mn;
        }
        for (int i = 1; i < n; i++) {
            if (mxxr[i-1] < mnnr[i] && mxxl[i] < mnnl[i-1]) {
                cout << "YES\n";
                string res(n, 'B');
                for (int k = 0; k < i; k++)
                    res[a[k][m]] = 'R';
                cout << res;
                cout << " ";
                cout << j;
                cout << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
