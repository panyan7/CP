#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

struct cmp {
    bool operator()(pii a, pii b) const {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> start(n+1, -1), end(n+1, -1);
    for (int i = 0; i < n; i++) {
        if (start[a[i]] == -1)
            start[a[i]] = i;
        end[a[i]] = max(end[a[i]], i);
    }
    vector<pii> seg;
    for (int i = 1; i <= n; i++) {
        if (start[i] != -1 && start[i] != end[i])
            seg.push_back({start[i], end[i]});
    }
    sort(seg.begin(), seg.end(), cmp());
    multiset<int> pq;
    int st = 0, j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (j < seg.size() && seg[j].first == i) {
            if (pq.empty() || (*pq.rbegin() < seg[j].second && pq.size() == 1)) {
                cnt++;
                pq.insert(seg[j].second);
            } else if (*pq.rbegin() < seg[j].second && pq.size() > 1) {
                pq.erase(*pq.rbegin());
                pq.insert(seg[j].second);
            }
            j++;
        }
        while (!pq.empty() && *pq.begin() == i) {
            pq.erase(pq.begin());
        }
        if (pq.size() == 0)
            cnt++;
    }
    cout << n-cnt << "\n";
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
