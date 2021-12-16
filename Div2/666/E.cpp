#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, r1, r2, r3, d;
vector<ll> a, dp0, dp1;

int main() {
    cin >> n >> r1 >> r2 >> r3 >> d;
    a.assign(n, 0);
    dp0.assign(n, 0);
    dp1.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp0[0] = r1*a[0]+r3;
    dp1[0] = min(r1*a[0]+r1, r2);
    for (int i = 1; i < n; ++i) {
        ll a0 = min(a[i]*r1+r1, r2);
        ll a1 = a[i]*r1+r3;
        dp0[i] = min(dp0[i-1]+a1, dp1[i-1]+2*d+min(a0+2*r1, a1+r1))+d;
        dp1[i] = min(dp0[i-1]+a0, dp1[i-1]+2*d+r1+a0)+d;
    }
    cout << min(dp0[n-1], dp1[n-2]+2*d+r1+a[n-1]*r1+r3) << "\n";
    return 0;
}
