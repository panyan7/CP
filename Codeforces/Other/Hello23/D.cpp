#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
int tt = 1, n, m, k;

struct UnionFind {
    int n;
    vector<int> parent, sz;
    UnionFind(int n_) : n(n_) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int v = 0; v < n; ++v)
            parent[v] = v;
    }
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    bool union_sets(int v, int u) {
        v = find_set(v), u = find_set(u);
        if (v == u)
            return false;
        if (sz[v] < sz[u])
            swap(v, u);
        parent[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cin >> m;
    vector<ll> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }
    }
    sort(c.begin(), c.end());
    map<ll,vector<ll>> mp;
    map<ll,ll> cnt;
    for (int i = 0; i < n; i++)
        mp[b[i]].push_back(i);
    for (int i = 0; i < m; i++)
        cnt[c[i]]++;
    UnionFind d(n);
    for (auto& [x,v] : mp) {
        set<int> st;
        for (int i : v) {
            if (i > 0 && b[i] >= b[i-1])
                d.union_sets(i, i-1);
            if (i < n-1 && b[i] >= b[i+1])
                d.union_sets(i, i+1);
        }
        for (int i : v) {
            if (a[i] == b[i])
                continue;
            st.insert(d.find_set(i));
        }
        if (st.size() > cnt[x]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
