#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> a;

ll f(ll x) {
    ll cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += abs(pow(x, i) - a[i]);
    }
    return cost;
}

int main() {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll lo = 1, hi = (ll)pow(1e15, 1.0/(n-1));
    while (lo + 2 < hi) {
        int mid1 = lo + (hi-lo)/3;
        int mid2 = hi - (hi-lo)/3;
        if (f(mid1) >= f(mid2)) lo = mid1;
        else hi = mid2;
    }
    int mid = lo + (hi-lo)/2;
    ll fm = f(mid), fl = f(lo), fh = f(hi);
    cout << min(fm, min(fl, fh)) << "\n";
    return 0;
}
