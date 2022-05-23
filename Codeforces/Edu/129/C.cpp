#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    vector<int> a2 = a, b2 = b;
    sort(a2.begin(), a2.end());
    sort(b2.begin(), b2.end());
    multiset<pii> c, c2;
    for (int i = 0; i < n; i++)
        c.insert({a[i], b[i]});
    for (int i = 0; i < n; i++)
        c2.insert({a2[i], b2[i]});
    if (c != c2) {
        cout << "-1\n";
        return;
    }
    vector<int> cur_index(n), cur_index_inv(n);
    for (int i = 0; i < n; i++)
        cur_index[i] = i;
    for (int i = 0; i < n; i++)
        cur_index_inv[i] = i;
    vector<pii> res;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[cur_index[j]] == a2[i] && b[cur_index[j]] == b2[i]) {
                if (i != j)
                    res.push_back({i, j});
                swap(cur_index[i], cur_index[j]);
                swap(cur_index_inv[i], cur_index_inv[j]);
                // swap(cur_index[cur_index_inv[i]], cur_index[j]);
                // swap(cur_index_inv[i], cur_index_inv[cur_index[j]]);
            }
        }
    }
    cout << res.size() << "\n";
    for (auto& p : res)
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
