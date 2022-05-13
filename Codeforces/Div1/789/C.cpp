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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        a[i]--, b[i]--;
    init();
    for (int i = 0; i < n; i++)
        union_sets(a[i], b[i]);
    ll res = 0;
    ll d = n-1;
    vector<int> order;
    for (int i = 0; i < n/2; i++) {
        order.push_back(i);
        order.push_back(n-1-i);
    }
    if (n % 2 == 1)
        order.push_back(n/2);
    reverse(order.begin(), order.end());
    vector<int> sizes;
    ll odd = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            if (sz[i] % 2 == 1)
                odd++;
            sizes.push_back(sz[i]);
        }
    }
    res = (n - 1LL + odd) * (n - odd) / 2LL + (n - odd) / 2LL;
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
