#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    cout << "? 1 " << n << "\n";
    cout.flush();
    ll total;
    cin >> total;
    ll lo = 1, hi = n;
    while (lo + 1 < hi) {
        ll mid = lo + (hi-lo)/2;
        cout << "? 1 " << mid << "\n";
        cout.flush();
        ll x; cin >> x;
        if (x >= total) hi = mid;
        else lo = mid;
    } 
    cout << "? 1 " << lo << "\n";
    cout.flush();
    k = hi;
    ll x; cin >> x;
    ll z = total - x + 1;
    ll yy = total - z*(z-1)/2;
    lo = 1, hi = n+1; 
    while (lo + 1 < hi) {
        ll mid = lo+(hi-lo)/2;
        if (mid*(mid-1)/2 > yy) hi = mid;
        else lo = mid;
    }
    ll y = lo;
    cout << "! " << k-z-y+1 << " " << k-z+1 << " " << k << "\n";
    cout.flush();
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
