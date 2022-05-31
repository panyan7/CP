#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cnt[a[i] % 2]++;
    cout << min(cnt[0], cnt[1]) << "\n";
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
