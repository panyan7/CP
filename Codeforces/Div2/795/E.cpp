#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(n);
    sz.assign(n, 1);
    for (int v = 0; v < n; ++v)
        parent[v] = v;
}
int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]); // Optimizes depth 
}
bool union_sets(int v, int u) {
    v = find_set(v), u = find_set(u);
    if (v == u)
        return false;
    if (sz[v] < sz[u])
        swap(v, u); // Optimizes depth
    parent[u] = v;
    sz[v] += sz[u];
    return true;
}

// check long long
void solve() {
    cin >> n;
    init();
    vector<array<ll,3>> a;
    vector<array<ll,4>> b;
    for (int i = 0; i < n; i++) {
        ll c, l, r;
        cin >> c >> l >> r;
        a.push_back({c, l, r});
        b.push_back({l, 0, c, i});
        b.push_back({r, 1, c, i});
    }
    sort(b.begin(), b.end());
    set<array<ll,2>> st[2] = {{}, {}};
    for (auto p : b) {
        if (p[1] == 0) {
            st[p[2]].insert({a[p[3]][2], p[3]});
            if (!st[p[2]^1].empty()) {
                for (auto& q : st[p[2]^1]) {
                    union_sets(p[3], q[1]);
                }
                while (st[p[2]^1].size() > 1)
                    st[p[2]^1].erase(st[p[2]^1].begin());
            }
        } else {
            st[p[2]].erase({a[p[3]][2], p[3]});
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            res++;
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
