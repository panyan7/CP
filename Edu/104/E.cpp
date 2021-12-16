#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

template <typename T>
class RMQ {
    vector<vector<T>> spt;
    int n, lim;
private:
    void _build (const vector<T>& a) {
        spt.assign(lim+1, vector<T>(n, 0));
        for (int i = 0; i < n; ++i)
            spt[0][i] = a[i];
        for (int k = 1; k <= lim; ++k)
            for (int i = 0; i <= n-(1<<k); ++i)
                spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
    }
public:
    RMQ(const vector<T>& a):
        n(a.size()), lim(floor(log2(n)+1)) { _build(a); }
    T query(int i, int j) const {
        int k = floor(log2(j-i+1));
        T res = min(spt[k][i], spt[k][j-(1<<k)+1]);
        return res;
    }
};

void write(vector<ll>& a) {
    for (auto& x : a)
        cout << x << " ";
    cout << "\n";
}

const ll INF = 1e12;
int t = 1, m, k;

void solve() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    array<int,4> n = {n1, n2, n3, n4};
    vector<vector<ll>> dp(4);
    vector<vector<ll>> a(4);
    a[0].resize(n1);
    for (auto& x : a[0])
        cin >> x;
    a[1].resize(n2);
    for (auto& x : a[1])
        cin >> x;
    a[2].resize(n3);
    for (auto& x : a[2])
        cin >> x;
    a[3].resize(n4);
    for (auto& x : a[3])
        cin >> x;
    dp[0] = a[0];
    for (int k = 1; k < 4; ++k) {
        RMQ<ll> Q(dp[k-1]);
        vector<set<int>> adj(n[k]);
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[v].insert(u);
        }
        dp[k] = vector<ll>(n[k]);
        for (int i = 0; i < n[k]; ++i) {
            int lst = 0;
            ll mn = INF;
            for (int v : adj[i]) {
                if (v-1 >= lst)
                    mn = min(mn, Q.query(lst, v-1));
                lst = v+1;
            }
            if (n[k-1]-1 >= lst)
                mn = min(mn, Q.query(lst, n[k-1]-1));
            dp[k][i] = mn + a[k][i];
            dp[k][i] = dp[k][i] >= INF ? INF : dp[k][i];
        }
    }
    ll res = *min_element(dp[3].begin(), dp[3].end());
    cout << (res >= INF ? -1 : res) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (t--) {
        solve();
    }
    return 0;
}
