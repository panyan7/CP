#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    string s;
    cin >> s;
    n = s.size();
    array<int,2> cnt = {0, 0};
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'0']++;
    }
    if (cnt[0] == cnt[1]) {
        cout << cnt[0]-1 << "\n";
    } else {
        cout << min(cnt[0], cnt[1]) << "\n";
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
