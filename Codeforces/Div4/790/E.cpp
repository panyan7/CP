#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n; i++)
        a[i] += a[i-1];
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end())
            cout << "-1\n";
        else
            cout << (int)(it - a.begin()+1) << "\n";
    }
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
