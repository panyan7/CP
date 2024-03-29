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

// const int MOD = 1e9+7;
const int MOD = 998244353;
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
num permute(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * ifact[a-b];
}
num choose(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * ifact[a-b] * ifact[b];
}

bool comp[MAXN];

void solve() {
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0;
    vector<num> dp(2*n+1);
    dp[0] = 1;
    while (i < 2*n) {
        int j = i;
        while (j < 2*n && a[j] == a[i]) j++;
        vector<num> cur(2*n+1);
        for (int k = 0; k <= j; k++) {
            // k bottom, j-k top
            if (k-1 >= 0 && !comp[a[i]])
                cur[k] += dp[k-1] * choose(j-k, j-i-1);
            cur[k] += dp[k] * choose(j-k, j-i);
        }
        dp = cur;
        i = j;
    }
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    comp[1] = true;
    for (int i = 2; i <= 1e6; i++) {
        for (int j = i*2; j <= 1e6; j += i) {
            comp[j] = true;
        }
    }
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
