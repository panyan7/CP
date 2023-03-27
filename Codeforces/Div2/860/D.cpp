#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll mx = a.back(), mn = a[0];
    if (mx == mn) {
        cout << "No\n";
        return;
    }
    queue<ll> pos, neg;
    for (int x : a)
        if (x >= 0)
            pos.push(x);
        else
            neg.push(x);
    ll cur = 0;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        ll x;
        if (cur <= 0) {
            x = pos.front();
            pos.pop();
        } else {
            x = neg.front();
            neg.pop();
        }
        cur += x;
        res[i] = x;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << "\n";
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
