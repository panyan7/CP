#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    ll cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
        if (s[0][i] == '*')
            cnt[0]++;
    for (int i = 0; i < n; i++)
        if (s[1][i] == '*')
            cnt[1]++;
    int l[2] = {0, 0}, r[2] = {0, 0};
    for (l[0] = 0; l[0] < n; l[0]++)
        if (s[0][l[0]] == '*')
            break;
    for (r[0] = n-1; r[0] >= 0; r[0]--)
        if (s[0][r[0]] == '*')
            break;
    for (l[1] = 0; l[1] < n; l[1]++)
        if (s[1][l[1]] == '*')
            break;
    for (r[1] = n-1; r[1] >= 0; r[1]--)
        if (s[1][r[1]] == '*')
            break;
    if (r[1] < 0) {
        cout << r[0]-l[0] << "\n";
        return;
    }
    if (r[0] < 0) {
        cout << r[1]-l[1] << "\n";
        return;
    }
    ll res = 0;
    if (l[1] >= r[0]) {
        cout << r[1] - l[0] + 1 << "\n";
        return;
    }
    if (l[0] >= r[1]) {
        cout << r[0] - l[1] + 1 << "\n";
        return;
    }
    if (l[0] <= l[1] && r[0] >= r[1]) {
        cout << cnt[1] + (r[0]-l[0]) << "\n";
        return;
    }
    if (l[1] <= l[0] && r[1] >= r[0]) {
        cout << cnt[0] + (r[1]-l[1]) << "\n";
        return;
    }
    if (l[0] <= l[1] && r[0] <= r[1]) {
        ll res = LLONG_MAX;
        ll base = r[1]-l[0]+1;
        ll cur0 = 0, cur1 = 0;
        for (int i = l[1]; i <= r[0]; i++)
            if (s[0][i] == '*')
                cur0++;
        for (int i = l[1]; i <= r[0]; i++) {
            // l[0]..i, i..r[1]
            if (s[0][i] == '*')
                cur0--;
            res = min(res, base + cur0 + cur1);
            if (s[1][i] == '*')
                cur1++;
        }
        cout << res << "\n";
        return;
    }
    if (l[1] <= l[0] && r[1] <= r[0]) {
        ll res = LLONG_MAX;
        ll base = r[0]-l[1]+1;
        ll cur0 = 0, cur1 = 0;
        for (int i = l[0]; i <= r[1]; i++)
            if (s[1][i] == '*')
                cur0++;
        for (int i = l[0]; i <= r[1]; i++) {
            // l[0]..i, i..r[1]
            if (s[1][i] == '*')
                cur0--;
            res = min(res, base + cur0 + cur1);
            if (s[0][i] == '*')
                cur1++;
        }
        cout << res << "\n";
        return;
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
