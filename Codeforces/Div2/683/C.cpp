#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    ll w;
    cin >> n >> w;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<pll> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i+1};
    sort(b.begin(), b.end());
    vector<ll> p(n, 0);
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        sm += b[i].first;
        if (sm*2 >= w && sm <= w) {
            cout << i+1 << "\n";
            for (int j = 0; j <= i; j++) {
                cout << b[j].second << " ";
            }
            cout << "\n";
            return;
        } else if (sm >= w) {
            if (b[i].first*2 >= w && b[i].first <= w) {
                cout << 1 << "\n";
                cout << b[i].second << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
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
