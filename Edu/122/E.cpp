#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m;
vector<ll> parent;
vector<ll> sz;

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
    cin >> n >> m;
    vector<array<ll,3>> edges(m);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, u, v};
    }
    ll p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<ll> queries;
    for (int i = 0; i < p; i++) {
        ll q; cin >> q;
        queries.push_back(q);
    }
    set<ll> crit;
    ll res = 0;
    crit.insert(0);
    crit.insert(c-1);
    for (int i = 0; i < m; i++) {
        crit.insert(edges[i][0]);
        for (int j = i; j < m; j++) {
            crit.insert((edges[i][0] + edges[j][0]) / 2);
            crit.insert(-1 + (edges[i][0] + edges[j][0]) / 2);
            //crit.insert(1 + (edges[i][0] + edges[j][0]) / 2);
        }
    }
    map<ll,pll> mp;
    for (ll x : crit) {
        init();
        sort(edges.begin(), edges.end(), [&](array<ll,3> a, array<ll,3> b) {
                if (abs(a[0] - x) == abs(b[0] - x))
                    return a[0] > b[0];
                return abs(a[0] - x) < abs(b[0] - x);
                });
        ll res = 0, num_pos = 0;
        for (int j = 0; j < m; j++) {
            if (find_set(edges[j][1]) != find_set(edges[j][2])){
                if (edges[j][0] > x) {
                    res += edges[j][0];
                    num_pos++;
                } else {
                    res -= edges[j][0];
                    num_pos--;
                }
                union_sets(edges[j][1], edges[j][2]);
            }
        }
        mp[x] = {res, num_pos};
        //cout << x << ":" << res << " " << num_pos << "\n";
    }
    ll final_res = 0;
    ll x = queries[p-1];
    for (int i = 0; i < p; i++) {
        auto it = mp.lower_bound(queries[i]);
        ll res = it->second.first - it->second.second * queries[i];
        final_res = final_res ^ res;
        //cout << queries[i] << " " << res << "\n";
    }
    for (int i = p; i < k; i++) {
        x = ((((x * a) % c) + b) % c);
        auto it = mp.lower_bound(x);
        ll res = it->second.first - it->second.second * x;
        final_res = final_res ^ res;
        //cout << queries[i] << " " << res << "\n";
    }
    cout << final_res << "\n";
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
