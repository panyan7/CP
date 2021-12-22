#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    int l = 0, r = 0, u = 0, d = 0;
    ll sx, sy;
    cin >> n >> sx >> sy;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x <= sx)
            l++;
        if (x >= sx)
            r++;
        if (y <= sy)
            u++;
        if (y >= sy)
            d++;
    }
    vector<array<ll,3>> ans = {{n-l,sx+1,sy}, {n-r,sx-1,sy}, {n-u,sx,sy+1}, {n-d,sx,sy-1}};
    sort(ans.begin(), ans.end());
    cout << ans[3][0] << "\n" << ans[3][1] << " " << ans[3][2] << "\n";
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
