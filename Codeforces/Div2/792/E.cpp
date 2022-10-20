#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n >> k;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; mp[x]++;
    }
    multiset<int> l, r;
    for (auto& p : mp)
        b.insert(p.second);
    ll res = 0, zero = 0, cnt = 0;
    for (int mex = 0; mex <= n; mex++) {
        while (!r.empty() && cnt + *r.begin() <= k) {
            cnt += *r.begin();
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        if (zero <= k)
            res = min(res, (ll)r.size());
        if (mp.count(mex) == 0)
            zero++;
        else {
        }
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
