#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<set<int>> adj;
vector<set<int>> leaves;

struct cmp {
    bool operator()(int a, int b) const {
        if (leaves[a].size() == leaves[b].size())
            return a < b;
        return leaves[a].size() > leaves[b].size();
    }
};

// check long long
void solve() {
    cin >> n >> k;
    adj.assign(n, set<int>());
    leaves.assign(n, set<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            leaves[*adj[i].begin()].insert(i);
        }
    }
    set<int, cmp> st;
    for (int i = 0; i < n; i++)
        st.insert(i);
    int res = 0;
    while (true) {
        int v = *st.begin();
        if (leaves[v].size() < k)
            break;
        for (int i = 0; i < k; i++) {
            int u = *leaves[v].begin();
            adj[v].erase(u);
            adj[u].erase(v);
            st.erase(v);
            st.erase(u);
            leaves[v].erase(u);
            if (leaves[u].find(v) != leaves[u].end())
                leaves[u].erase(v);
            if (adj[v].size() == 1) {
                int w = *adj[v].begin();
                st.erase(w);
                leaves[w].insert(v);
                st.insert(w);
            }
            st.insert(v);
            st.insert(u);
        }
        res++;
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
