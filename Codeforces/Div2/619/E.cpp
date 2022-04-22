#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k, q;
char board[505][505];
int pt[253][505][505];
int ps[253][505][505];
 
// check long long
void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
        }
    }
    vector<vector<pii>> lu(min(n,m)/2+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= min(n,m)/2; k++) {
                bool can = true;
                if (i-k+1 < 0 || j-k+1 < 0 || i+k >= n || j+k >= m)
                    break;
                for (int l = j-k+1; l <= j; l++) {
                    if (board[i-k+1][l] != 'R')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = i-k+1; l <= i; l++) {
                    if (board[l][j-k+1] != 'R')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = j+1; l <= j+k; l++) {
                    if (board[i-k+1][l] != 'G')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = i-k+1; l <= i; l++) {
                    if (board[l][j+k] != 'G')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = j-k+1; l <= j; l++) {
                    if (board[i+k][l] != 'Y')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = i+1; l <= i+k; l++) {
                    if (board[l][j-k+1] != 'Y')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = j+1; l <= j+k; l++) {
                    if (board[i+k][l] != 'B')
                    { can = false; break; }
                }
                if (!can)
                    break;
                for (int l = i+1; l <= i+k; l++) {
                    if (board[l][j+k] != 'B')
                    { can = false; break; }
                }
                if (!can)
                    break;
                lu[k].push_back({i-k+1, j-k+1});
            }
        }
    }
    vector<array<int,4>> query;
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        query.push_back({r1, c1, r2, c2});
    }
    vector<int> res(q, 0);
    for (int k = 1; k <= min(m,n)/2; k++) {
        for (auto p : lu[k])
            pt[k][p.first+1][p.second+1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[k][i][j] = ps[k][i][j-1] + pt[k][i][j];
            }
            for (int j = 1; j <= m; j++) {
                ps[k][i][j] += ps[k][i-1][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        auto p = query[i];
        auto check = [&](int k) {
            if (p[2] - p[0] + 1 < 2*k)
                return true;
            if (p[3] - p[1] + 1 < 2*k)
                return true;
            int sm = ps[k][p[2]-2*k+1][p[3]-2*k+1] - ps[k][p[2]-2*k+1][p[1]-1] - ps[k][p[0]-1][p[3]-2*k+1] + ps[k][p[0]-1][p[1]-1];
            if (sm > 0)
                return false;
            return true;
        };
        int lo = 0, hi = min(m,n)/2;
        if (!check(hi)) {
            res[i] = 4 * hi * hi;
            continue;
        }
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) hi = mid;
            else lo = mid;
        }
        res[i] = 4 * lo * lo;
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
