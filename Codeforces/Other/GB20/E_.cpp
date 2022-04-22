#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <int MOD>
struct modnum {
    int v;
    modnum() : v(0) {}
    modnum(int64_t v_) : v(int(v_ % MOD)) {}

    explicit operator int() const { return v; }

    friend ostream& operator << (ostream& o, const modnum& m) {
        return o << int(m);
    }
    friend istream& operator >> (istream& i, const modnum& m) {
        int64_t val;
        i >> val;
        m = modnum(val);
        return i;
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
    modnum& operator /= (const modnum& o) { return *this *= inv(o); }

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

const int MOD = 1e9+7;
typedef modnum<MOD> num;
ll t, n, cnt[64];
ll x[500005];

void solve() {
    num s = 0, res = 0;
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        s += num(x[i]);
        for (int j = 0; j < 64; ++j) {
            cnt[j] += (x[i] >> j) & 1;
        }
    }
    for (int j = 1; j <= n; ++j) {
        num sj = 0;
        for (int k = 0; k < 64; ++k) {
            ll cj = (x[j] >> k) & 1;
            sj += num((1LL << k) * max(cnt[k], cj*n));
        }
        res += (num(n*x[j]) + s) * sj;
        res -= sj * sj;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
