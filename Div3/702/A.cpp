#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    cin >> n;
    int cnt = 0;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 1; i < n; ++i) {
        double mx = max(a[i], a[i-1]);
        double mn = min(a[i], a[i-1]);
        if (mx > 2 * mn)
            cnt += ceil(log2(mx/mn))-1;
    }
    cout << cnt << "\n";
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
