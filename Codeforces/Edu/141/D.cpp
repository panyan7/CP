#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<int64_t,int64_t>

template <typename T, int LB = 0, int UB = 0>
struct ArrayMap {
    int lb = LB, ub = UB;
    vector<T> data;
    ArrayMap() : data(ub-lb+1) {}
    ArrayMap(int lb_, int ub_) : lb(lb_), ub(ub_), data(ub-lb+1) {}
    ArrayMap(int lb_, int ub_, T v) : lb(lb_), ub(ub_), data(ub-lb+1, v) {}
    const size_t size() const           { return data.size(); }
    T& operator[](size_t i)             { return data[(int)i-lb]; }
    const T& operator[](size_t i) const { return data[(int)i-lb]; }
    friend ostream& operator<<(ostream& os, const ArrayMap& mp) {
        for (int i = 0; i < mp.size(); i++)
            os << mp[i] << " \n"[i+1 == mp.size()];
        return os;
    }
};

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

// const int MOD = 1e9+7;
const int MOD = 998244353;
using num = ModNum<MOD>;
int tt = 1, n, m;
ArrayMap<num,-90400,90400> dp[310];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    dp[1][a[1]] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = -90000; j <= 90000; j++) {
            dp[i][a[i] + j] += dp[i-1][j];
            if (j != 0)
                dp[i][a[i] - j] += dp[i-1][j];
        }
    }
    num res = 0;
    for (int j = -90000; j <= 90000; j++) {
        res += dp[n-1][j];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
