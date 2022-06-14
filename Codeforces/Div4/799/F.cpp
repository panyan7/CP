#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % 10]++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] == 0)
            continue;
        cnt[i]--;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] == 0)
                continue;
            cnt[j]--;
            for (int k = 0; k < 10; k++) {
                if (cnt[k] == 0)
                    continue;
                if ((i + j + k) % 10 == 3) {
                    cout << "YES\n";
                    return;
                }
            }
            cnt[j]++;
        }
        cnt[i]++;
    }
    cout << "NO\n";
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
