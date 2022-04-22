#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

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
// const int MOD = 998244353;
using num = ModNum<MOD>;
ll tt = 1, n, m, p;
num dp[200005], pf[200005];

void solve() {
    cin >> n >> p;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    unordered_set<ll> st;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        st.insert(a[i]);
    vector<bool> ok(n, true);
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        while (x > 0) {
            if (x % 2 == 1)
                x /= 2;
            else if (x % 4 == 0)
                x /= 4;
            else
                break;
            if (st.count(x)) {
                ok[i] = false;
                break;
            }
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    pf[0] = 1;
    pf[1] = 2;
    for (int i = 2; i <= max(2LL, p); i++) {
        dp[i] = dp[i-1] + dp[i-2];
        pf[i] = pf[i-1] + dp[i];
    }
    num res = 0;
    for (int i = 0; i < n; i++) {
        if (!ok[i])
            continue;
        ll bits = 64-__builtin_clzll(a[i]);
        if (p - bits >= 0)
            res += pf[p - bits];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
