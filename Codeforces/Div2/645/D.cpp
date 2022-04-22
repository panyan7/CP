#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
ll d[400005], s[400005];

// check long long
void solve() {
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = n+1; i <= 2*n; i++)
        d[i] = d[i-n];
    for (int i = 2*n; i >= 1; i--)
        s[i] = s[i+1] + d[i];
    int k = 2*n+1;
    ll sm = 0, res = 0;
    for (int i = 2*n; i >= 1; i--) {
        sm -= (d[i+1] + 1) * d[i+1] / 2;
        while (k >= 1 && s[k] - s[i+1] < x) {
            k--;
            sm += (d[k] + 1) * d[k] / 2;
        }
        if (s[k] - s[i+1] < x)
            break;
        ll hug = sm - (s[k] - s[i+1] - x + 1) * (s[k] - s[i+1] - x) / 2;
        res = max(res, hug);
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
