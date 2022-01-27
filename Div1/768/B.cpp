#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n >> k;
    vector<int> a(n), cnt(n+1, 0), p(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        p[i] = cnt[i] + p[i-1];
    int lo = -1, hi = n;
    vector<int> xs(n+1, 0);
    auto check = [&](int mid) {
        if (mid == -1)
            return false;
        for (int i = 1; i+mid <= n; i++) {
            int c = p[i+mid] - p[i-1];
            int b = n - c;
            if (c - b >= k) {
                xs[mid] = i;
                return true;
            }
        }
        return false;
    };
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    check(hi);
    cout << xs[hi] << " " << xs[hi] + hi << "\n";
    int c = 0, start = 0;
    vector<pii> res;
    for (int i = 0; i < n; i++) {
        if ((int)res.size() == k-1) {
            res.push_back({start, n-1});
            break;
        }
        if (a[i] >= xs[hi] && a[i] <= xs[hi] + hi)
            c++;
        else 
            c--;
        if (c > 0) {
            res.push_back({start, i});
            start = i+1;
            c = 0;
        }
    }
    assert(res.size() == k);
    for (auto p : res)
        cout << p.first+1 << " " << p.second+1 << "\n";
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
