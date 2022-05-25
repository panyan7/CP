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
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<int> res;
    for (int i = 0; i < n/2; i++) {
        res.push_back(a[i]);
        res.push_back(a[i+n/2]);
    }
    for (int i = 1; i < n-1; i++) {
        if (res[i] == res[i-1] || res[i] == res[i+1]) {
            cout << "NO\n";
            return;
        }
    }
    if (res[0] == res[1] || res[0] == res[n-1]) {
        cout << "NO\n";
        return;
    }
    if (res[n-1] == res[n-2] || res[n-1] == res[0]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
