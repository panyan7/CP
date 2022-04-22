#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;

template <int MOD>
struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(int64_t v_) : v(int(v_ % MOD)) {}
    explicit operator int() const { return v; }
    friend ostream& operator << (ostream& os, const modnum& m) {
        return os << int(m);
    }
    friend istream& operator >> (istream& is, modnum& m) {
        return is >> m.v;
    }
    modnum& operator ++ () {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum operator ++ (int) {
        modnum r = *this;
        ++*this;
        return r;
    }
    modnum& operator -- () {
        --v;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum operator -- (int) {
        modnum r = *this;
        --*this;
        return r;
    }
    modnum neg() const {
        modnum r = *this;
        if (v == 0) r.v = MOD;
        else r.v = MOD - v;
        return r;
    }
private:
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
public:
    modnum inv() const { assert(v); return modnum(minv(v, MOD)); }
    modnum& operator += (const modnum& o) {
        v -= MOD - o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0 ? v + MOD : v);
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }
    friend modnum operator + (const modnum& a, const modnum& b) {
        return modnum(a) += b;
    }
    friend modnum operator - (const modnum& a, const modnum& b) {
        return modnum(a) -= b;
    }
    friend modnum operator * (const modnum& a, const modnum& b) {
        return modnum(a) *= b;
    }
    friend modnum operator / (const modnum& a, const modnum& b) {
        return modnum(a) /= b;
    }
    friend modnum pow(const modnum& a, int e) {
        modnum res = 1;
        while (e) {
            if (e % 2) res *= a;
            e /= 2;
            a *= a;
        }
        return res;
    }
};

typedef modnum<MOD> num;
int t, n, k, q;

void solve() {
    cin >> n >> k >> q;
    vector<int> a (n, 0);
    for (auto& x : a) cin >> x;
    vector<vector<num>> dp (n, vector<num> (n, 0));
    // dp[i][j] == number of times a good path that ends in i passes j
    dp[1][0] = 2; dp[1][n-1] = 2;
    for (int i = 1; i < n-1; ++i)
        dp[1][i] = 4;
    for (int l = 2; l <= k; ++l) {
        for (int i = 0; i < n; ++i) {
            vector<vector<num>> dpn (n, vector<num> (n, 0));
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    dpn[i][j] += dp[i-1][];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
