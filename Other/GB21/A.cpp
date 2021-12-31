#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int cnt[105], a[105];

// check long long
void solve() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cnt[abs(a[i])]++;
    int res = 0;
    for (int i = 0; i <= 100; i++) {
        if (i != 0 && cnt[i] >= 2)
            res += 2;
        else if (cnt[i] > 0)
            res++;
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
