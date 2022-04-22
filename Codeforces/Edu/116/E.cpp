#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int(v_ % MOD)) {}
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

//const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
int t = 1;
num dp[505][505], choose[505][505];

void solve() {
    ll n, x;
    cin >> n >> x;
    num res = 0;
    choose[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        choose[i][0] = 1;
        choose[i][i] = 1;
        for (int j = 1; j <= i-1; j++) {
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << choose[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for (ll j = 1; j <= x; j++)
        dp[0][j] = 1;
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= x; j++) {
            if (j <= i-1) {
                dp[i][j] = pow(num(j), i);
                continue;
            }
            // k heroes die, others dp[n-k][x-n+1];
            // deal i-1 damage to all characters
            // heroes that die have health <= i-1, (i-1)^k ways
            // heroes that live satisfy j-i+1
            for (ll k = 0; k <= i-2; k++) {
                dp[i][j] += dp[i-k][j-i+1] * choose[i][k] * pow(num(i-1), k);
            }
            dp[i][j] += dp[0][j-i+1] * choose[i][i] * pow(num(i-1), i);
        }
    }
    cout << dp[n][x] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
