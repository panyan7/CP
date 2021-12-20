#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

pll make_sort_pair(ll a, ll b) {
    return {min(a, b), max(a, b)};
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    vector<pll> pa, pb;
    for (int i = 0; i < n/2; i++) {
        pa.push_back(make_sort_pair(a[i], a[n-i-1]));
        pb.push_back(make_sort_pair(b[i], b[n-i-1]));
    }
    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());
    if (n % 2 == 1 && a[n/2] != b[n/2]) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n/2; i++) {
        if (pa[i] != pb[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
