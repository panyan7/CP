#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
 
template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator<<(ostream& os, const ModNum& m) {
        return os << m.v;
    }
    friend istream& operator>>(istream& is, ModNum& m) {
        return is >> m.v;
    }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    ModNum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator++(int) {
        ModNum r = *this;
        ++*this;
        return r;
    }
    ModNum& operator--() {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    ModNum operator--(int) {
        ModNum r = *this;
        --*this;
        return r;
    }
    ModNum neg() const { return ModNum(v == 0 ? 0 : MOD - v); }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    ModNum inv() const { assert(v); return ModNum(minv(v, MOD)); }
    ModNum& operator+=(const ModNum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator-=(const ModNum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    ModNum& operator*=(const ModNum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& o) {
        return *this *= o.inv();
    }
    friend ModNum operator+(const ModNum& a, const ModNum& b) {
        return ModNum(a) += b;
    }
    friend ModNum operator-(const ModNum& a, const ModNum& b) {
        return ModNum(a) -= b;
    }
    friend ModNum operator*(const ModNum& a, const ModNum& b) {
        return ModNum(a) *= b;
    }
    friend ModNum operator/(const ModNum& a, const ModNum& b) {
        return ModNum(a) /= b;
    }
    friend ModNum pow(const ModNum& a, int e) {
        ModNum res = 1;
        ModNum b(a);
        while (e) {
            if (e % 2) res *= b;
            e /= 2;
            b *= b;
        }
        return res;
    }
};

const int MOD = 1e9+7;
using num = ModNum<MOD>;
const int MAXN = 105;
int t = 1, n, m, k;
num choose[MAXN][MAXN];
 
void solve() {
    // check long long
    num res = 0;
    cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k == 2) {
        cout << choose[n][k] << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (adj[i].size() >= k) {
            vector<bool> vis(n, 0);
            vector<vector<int>> dist(n, vector<int>(n+1, 0));
            function<void(int)> dfs = [&](int v) {
                vis[v] = true;
                dist[v][0] = 1;
                for (int u : adj[v]) {
                    if (!vis[u]) {
                        dfs(u);
                        for (int i = 1; i < n; i++) {
                            dist[v][i] += dist[u][i-1];
                        }
                    }
                }
            };
            vis[i] = true;
            for (int v : adj[i])
                dfs(v);
            for (int c = 0; c <= n; c++) {
                int d = adj[i].size();
                vector<vector<num>> dp(d+1, vector<num>(k+1, 0));
                dp[0][0] = 1;
                for (int m = 1; m <= d; m++) {
                    dp[m][0] = 1;
                    for (int l = 1; l <= k; l++) {
                        dp[m][l] = dp[m-1][l] + num(dist[adj[i][m-1]][c]) * dp[m-1][l-1];
                    }
                }
                res += num(dp[d][k]);
            }
        }
    }
    cout << res << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < MAXN; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
        }
    }
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

