#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    if (n == 2) {
        cout << "3 1\n";
        return;
    }
    ll a = 2 * n;
    ll b = a * a - (ll)(n - 2) * (n - 1) / 2 - a;
    b = b / n;
    // cout << b * n + (n-1) * n / 2 << " " << a * a << " ";
    vector<ll> res(n, b);
    for (int i = 1; i < n; i++)
        res[i] += i;
    res[n-1] = a + b;
    ll s = accumulate(res.begin(), res.end(), 0LL);
    ll d = a * a - s;
    for (int j = n-2; j > 0; j--) {
        res[j] += d / (n-2);
    }
    d %= (n-2);
    for (int j = n-2; j > 0; j--) {
        if (d > 0)
            res[j]++, d--;
    }
    for (int x : res)
        cout << x << " ";
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
