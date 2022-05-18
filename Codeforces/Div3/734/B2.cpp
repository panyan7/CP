#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int t = 1, n, m, k;
 
void solve() {
    // check long long
    cin >> n >> k;
    vector<int> a(n), cnt(n+1, 0);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = min(cnt[i], k);
        sm += cnt[i];
    }
    int r = sm % k;
    for (int i = n; i >= 1; i--) {
        if (cnt[i] <= r) {
            r -= cnt[i];
            cnt[i] = 0;
        } else {
            cnt[i] -= r;
            break;
        }
    }
    vector<int> cnt2(n+1, 0);
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + min(cnt[i-1], k);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (cnt2[a[i]] >= cnt[a[i]]) {
            res.push_back(0);
        } else {
            int color = ((pref[a[i]] + cnt2[a[i]]) % k);
            color++;
            cnt2[a[i]]++;
            res.push_back(color);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
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
