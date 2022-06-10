#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<int> parent;
vector<int> sz;

void init() {
    parent.resize(30);
    sz.assign(30, 1);
    for (int v = 0; v < 30; ++v)
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

bool connected(vector<ll>& c) {
    init();
    vector<bool> vis(30, 0);
    for (int i = 0; i < n; i++) {
        ll x = c[i];
        int lb = x & (-x);
        lb = 31 - __builtin_clz(lb);
        while (x) {
            int b = x & (-x);
            b = 31 - __builtin_clz(b);
            vis[b] = true;
            union_sets(b, lb);
            x -= (1 << b);
            lb = b;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 30; i++) {
        if (vis[i] && find_set(i) == i)
            cnt++;
    }
    return cnt == 1;
}

void solve() {
    cin >> n;
    init();
    vector<ll> a(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            a[i]++;
            res++;
        }
    }
    if (connected(a)) {
        cout << res << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i]++;
        if (connected(a)) {
            cout << res + 1 << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
            return;
        }
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        a[i]--;
        if (connected(a)) {
            cout << res + 1 << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
            return;
        }
        a[i]++;
    }
    map<int,vector<int>,greater<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] & (-a[i])].push_back(i);
    }
    auto it = mp.begin();
    a[it->second[0]]--;
    res++;
    if (it->second.size() > 1) {
        a[it->second[1]]++;
        res++;
    }
    cout << res << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
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
