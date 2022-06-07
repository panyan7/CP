#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector<ll> b;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] / k;
        b.push_back(a[i] % k);
    }
    sort(b.begin(), b.end());
    int l = 0, r = n-1;
    while (l < r) {
        while (l < r && b[l] + b[r] < k)
            l++;
        if (l < r)
            res++;
        l++, r--;
    }
    cout << res << "\n";
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
