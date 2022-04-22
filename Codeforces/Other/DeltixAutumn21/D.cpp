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

struct cmp {
    bool operator()(int u, int v) const {
        u = find_set(u), v = find_set(v);
        if (sz[u] == sz[v])
            return u < v;
        return sz[u] > sz[v];
    }
};

// check long long
void solve() {
    cin >> n >> m;
    int res = 0;
    init();
    int num = 1;
    set<int, cmp> st;
    for (int i = 0; i < n; i++)
        st.insert(i);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        st.erase(find_set(u));
        st.erase(find_set(v));
        bool can = union_sets(u, v);
        st.insert(find_set(u));
        if (!can)
            num++;
        int cur = 0;
        auto it = st.begin();
        for (int i = 0; i < num; i++) {
            if (it == st.end())
                break;
            cur += sz[find_set(*it)];
            ++it;
        }
        res = max(res, cur-1);
        cout << res << "\n";
    }
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
