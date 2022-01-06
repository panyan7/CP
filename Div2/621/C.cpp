#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
ll cnt[100005][26], num[26][26];

// check long long
void solve() {
    string s;
    cin >> s;
    n = s.size();
    memset(cnt, 0, sizeof(cnt));
    memset(num, 0, sizeof(num));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i+1][j];
        cnt[i][s[i]-'a']++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            num[s[i]-'a'][j] += cnt[i+1][j];
        }
    }
    ll res = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            res = max(res, num[i][j]);
    for (int i = 0; i < 26; i++)
        res = max(res, cnt[0][i]);
    for (int i = 0; i < 26; i++)
        res = max(res, cnt[0][i] * (cnt[0][i] - 1) / 2);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
