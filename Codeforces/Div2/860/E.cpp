#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> res(n);
    vector<bool> r(n+1, 0);
    vector<int> len(n+1, 0);
    vector<int> mx(n+1, 0);
    int max_len = 0;
    r[n] = true;
    for (int i = n-1; i >= 0; i--) {
        int j = i + a[i] + 1;
        if (j <= n)
            len[i] = 1 + len[j];
        else
            len[i] = 1;
        if (j <= n)
            r[i] = r[j];
        else
            r[i] = false;
        mx[i] = max_len + 1;
        if (j <= n)
            mx[i] = max(mx[i], 1 + mx[j]);
        if (r[i])
            max_len = max(max_len, len[i]);
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == len[i+1] && r[i+1])
            res[i] = 0;
        else if (r[i+1])
            res[i] = 1;
        else if (len[i+1] >= a[i])
            res[i] = 1;
        else if (mx[i+1] >= a[i])
            res[i] = 1;
        else
            res[i] = 2;
    }
    for (int i = 0; i < n-1; i++)
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
