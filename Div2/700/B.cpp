#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll t = 1, n, m, k;

void solve() {
    ll A, B;
    cin >> A >> B >> n;
    vector<pll> mos(n, {0, 0});
    for (int i = 0; i < n; ++i)
        cin >> mos[i].first;
    for (int i = 0; i < n; ++i) 
        cin >> mos[i].second;
    sort(mos.begin(), mos.end());
    bool can = true;
    for (int i = 0; i < n; ++i) {
        if (B <= 0) {
            can = false;
            break;
        }
        ll tf = (mos[i].second+A-1)/A;
        if (B <= (tf-1) * mos[i].first) {
            can = false;
            break;
        }
        B -= tf * mos[i].first;
    }
    cout << (can ? "YES" : "NO") << "\n";
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
