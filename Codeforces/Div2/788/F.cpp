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
ll tt = 1, n, m, z;
num C[1005][1005];
map<ll,num> mem[64];

num calc(ll r, ll b) {
    if (b < 0)
        return (int)(r >= 0);
    if (b <= 50 && ((1LL << (b+1LL)) - 1LL) * n <= r)
        return pow(pow(num(2), n-1), b+1);
    if (mem[b].count(r))
        return mem[b][r];
    num res = 0;
    for (ll j = (z >> b) & 1LL; j <= min(n, r >> b); j += 2)
        res += C[n][j] * calc(r - j * (1LL << b), b-1);
    return mem[b][r] = res;
}

void solve() {
    ll l, r;
    cin >> n >> l >> r >> z;
    //cout << calc(r, 60);
    cout << calc(r, 60) - calc(l-1, 60) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 1000; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

