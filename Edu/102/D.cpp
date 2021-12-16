#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()
 
int t, n, m;
 
vector<vector<int>> mn, mx;
 
void build(vector<int>& a) {
    int kmx = floor(log2(n+1)+1);
    mn.assign(kmx+1, vector<int> (n+1, 0));
    mx.assign(kmx+1, vector<int> (n+1, 0));
    for (int i = 0; i <= n; ++i) {
        mn[0][i] = a[i];
        mx[0][i] = a[i];
    }
    for (int k = 1; k <= kmx; ++k) {
        for (int i = 0; i <= n+1-(1<<k); ++i) {
            mn[k][i] = min(mn[k-1][i], mn[k-1][i+(1<<(k-1))]);
            mx[k][i] = max(mx[k-1][i], mx[k-1][i+(1<<(k-1))]);
        }
    }
}
 
int mnquery(int i, int j) {
    int k = floor(log2(j-i+1));
    return min(mn[k][i], mn[k][j-(1<<k)+1]);
}
int mxquery(int i, int j) {
    int k = floor(log2(j-i+1));
    return max(mx[k][i], mx[k][j-(1<<k)+1]);
}
 
void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a (n+1, 0);
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == '+') a[i] = a[i-1]+1;
        else a[i] = a[i-1]-1;
    }
    build(a);
    int l, r;
    while (m--) {
        cin >> l >> r;
        int mx1 = mxquery(0, l-1);
        int mn1 = mnquery(0, l-1);
        if (r >= n) {
            cout << (mx1-mn1+1) << "\n";
            continue;
        }
        int mx2 = mxquery(r+1, n)-a[r]+a[l-1];
        int mn2 = mnquery(r+1, n)-a[r]+a[l-1];
        cout << (max(mx2, mx1)-min(mn1, mn2)+1) << "\n";
    }
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
