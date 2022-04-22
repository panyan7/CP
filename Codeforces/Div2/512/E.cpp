#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int c[300005], p[300005];

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        c[i+1] = __builtin_popcountll(a[i]);
        p[i+1] = p[i] + c[i+1];
    }
    int l = 0, r = 0;
    ll num[2] = {0, 0};
    ll res = 0;
    for (int i = 0; i <= n; i++)
        num[p[i] % 2]++;
    // cout << num[0] << " " << num[1] << "\n";
    res += num[0] * (num[0] - 1) / 2;
    res += num[1] * (num[1] - 1) / 2;

    for (int i = 1; i <= n; i++) {
        int r = i;
        int mx = 0, sm = 0;
        while (r <= n) {
            if (sm >= 150)
                break;
            mx = max(c[r], mx);
            sm += c[r];
            if ((p[r] - p[i-1]) % 2 == 0 && sm < mx * 2)
                res--;
            r++;
        }
    }
    cout << res << "\n";
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
