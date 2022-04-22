#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cnt[a[i]-'0'][b[i]-'0']++;
    }
    int ans = 1e9;
    if (cnt[0][1] == cnt[1][0])
        ans = 2 * cnt[0][1];
    if (cnt[1][1] == cnt[0][0] + 1)
        ans = min(ans, 2 * cnt[0][0] + 1);
    cout << (ans == 1e9 ? -1 : ans) << "\n";
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
