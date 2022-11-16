#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    int x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> cnt(x+1);
    for (auto& x : a)
        cin >> x;
    for (auto x : a)
        cnt[x]++;
    bool ok = true;
    for (int i = 1; i <= x; i++) {
        if (cnt[i-1] % i != 0) {
            ok = false;
            break;
        }
        cnt[i] += cnt[i-1] / i;
    }
    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
