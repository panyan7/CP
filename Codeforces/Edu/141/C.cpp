#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<pii> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};
    sort(b.begin(), b.end());
    int lo = -1, hi = n; 
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        bool ok = false;
        int num_wins = 0, cur_m = m;
        for (int i = 0; i < n; i++) {
            if (cur_m >= b[i].first) {
                cur_m -= b[i].first;
                num_wins++;
            }
        }
        if (num_wins >= mid+1) {
            ok = true;
        }
        num_wins = 0, cur_m = m;
        if (cur_m >= a[mid]) {
            cur_m -= a[mid];
            num_wins++;
            for (int i = 0; i < n; i++) {
                if (b[i].second != mid && cur_m >= b[i].first) {
                    cur_m -= b[i].first;
                    num_wins++;
                }
            }
            if (num_wins >= mid) {
                ok = true;
            }
        }
        if (ok)
            lo = mid;
        else
            hi = mid;
    }
    cout << n-lo << "\n";
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
