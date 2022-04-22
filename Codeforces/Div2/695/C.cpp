#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n1, n2, n3, m;
ll min2(ll a, ll b, ll c) {
    if (a > b) {
        if (a < c) return a+b;
        else return b+c;
    } else {
        if (b < c) return a+b;
        else return a+c;
    }
}

void solve() {
    cin >> n1 >> n2 >> n3;
    int n = n1 + n2 + n3;
    // vector<int> a1 (n1, 0), a2 (n2, 0), a3 (n3, 0);
    ll s1 = 0, s2 = 0, s3 = 0;
    ll mx1 = 0, mx2 = 0, mx3 = 0;
    ll mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
    for (int i = 0; i < n1; ++i) {
        ll x; cin >> x; s1 += x;
        mx1 = max(x, mx1); mn1 = min(x, mn1);
    }
    for (int i = 0; i < n2; ++i) {
        // cin >> a2[i];
        ll x; cin >> x; s2 += x;
        mx2 = max(x, mx2); mn2 = min(x, mn2);
    }
    for (int i = 0; i < n3; ++i) {
        // cin >> a3[i];
        ll x; cin >> x; s3 += x;
        mx3 = max(x, mx3); mn3 = min(x, mn3);
    }
    ll res1 = s1+s2+s3-2*min(s1, min(s2,s3));
    ll res2 = s1+s2+s3-2*min2(mn1, mn2, mn3);
    cout << max(res1, res2) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
