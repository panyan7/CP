#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m;
const ll MAXN = 200050;
ll a[MAXN], b[MAXN], c[MAXN], p[MAXN];
ll pc[MAXN], pcr[MAXN], pp[MAXN], ppr[MAXN];

// check long long
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 2; i <= n; i++) {
        c[i] += b[i]-a[i];
        p[i]--;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                c[i] -= (b[j]-a[j]);
                p[i] -= p[j];
                if (j*j != i) {
                    c[i] -= (b[i/j]-a[i/j]);
                    p[i] -= p[i/j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        c[i] = c[i] - a[1] * p[i];

    for (int i = 1; i <= n; i++) {
        if (p[i] < 0LL) {
            c[i] = -c[i];
            p[i] = -p[i];
        }
    }
    
    vector<array<ll,3>> vt;
    for (int i = 2; i <= n; i++) {
        ll k = 0LL;
        if (c[i] < 0LL) {
            if (p[i] == 0) {
                k = LLONG_MAX;
            } else {
                k = (-c[i]+p[i]-1)/p[i];
            }
        }
        vt.push_back({k, c[i], p[i]});
    }
    sort(vt.begin(), vt.end());
    ll sm = 0;
    for (int i = 0; i < n-1; i++) {
        sm += vt[i][1];
        pc[i] = sm;
    }
    sm = 0;
    for (int i = n-2; i >= 0; i--) {
        sm += vt[i][1];
        pcr[i] = sm;
    }
    sm = 0;
    for (int i = 0; i < n-1; i++) {
        sm += vt[i][2];
        pp[i] = sm;
    }
    sm = 0;
    for (int i = n-2; i >= 0; i--) {
        sm += vt[i][2];
        ppr[i] = sm;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll x; cin >> x;
        if (n == 1) {
            cout << abs(x-a[1]) << "\n";
            continue;
        }
        if (vt[0][0] >= x) {
            cout << abs(x-a[1])-pcr[0]-ppr[0]*x << "\n";
            continue;
        }
        if (vt[n-2][0] <= x) {
            cout << abs(x-a[1])+pc[n-2]+pp[n-2]*x << "\n";
            continue;
        }
        ll lo = 0, hi = n-2;
        while (lo+1 < hi) {
            ll mid = lo + (hi-lo)/2;
            if (vt[mid][0] >= x)
                hi = mid;
            else
                lo = mid;
        }
        ll res = pc[lo]-pcr[hi]+pp[lo]*x-ppr[hi]*x;
        cout << abs(x-a[1])+res << "\n";
    }
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
