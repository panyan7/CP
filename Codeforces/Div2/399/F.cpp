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
int tt = 1, n, m;
const int MAXN = 1e6+10;
num fact[MAXN], ifact[MAXN], inum[MAXN];

void init() {
    inum[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        inum[i] = MOD - (MOD/i) * inum[MOD % i];
    fact[0] = 1, ifact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i;
    for (int i = 1; i < MAXN; i++)
        ifact[i] = ifact[i-1] * inum[i];
}
num permute(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * ifact[a-b];
}
num choose(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * ifact[a-b] * ifact[b];
}

void solve() {
    ll f, w, h;
    cin >> f >> w >> h;
    ll fs = 0, ws = 0;
    num res = 0;
    auto calc = [&](ll fs, ll ws) {
        num diff = choose(f-1, fs-1) * choose(w-ws*h-1,ws-1);
        res += diff;
    };
    if (w == 0) {
        cout << "1\n";
        return;
    }
    if (f == 0) {
        cout << (w <= h ? 0 : 1) << "\n";
        return;
    }
    for (fs = 0; fs <= f; fs++) {
        calc(fs, fs-1);
        calc(fs, fs);
        calc(fs, fs);
        calc(fs, fs+1);
    }
    cout << res / choose(f+w, w) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
