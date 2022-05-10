#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int l[5005][5005], r[5005][5005];

void solve() {
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            l[i][j] = r[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            l[i][j] = l[i][j-1];
            if (p[j] < p[i])
                l[i][j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            r[i][j] = r[i][j+1];
            if (p[j] < p[i])
                r[i][j]++;
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            res += (ll)l[j][i-1] * r[i][j+1];
        }
    }
    cout << res << "\n";
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
