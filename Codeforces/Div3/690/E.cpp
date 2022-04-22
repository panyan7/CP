#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int t, k, m, n;
num fact[200005], mf;

void solve() {
    cin >> n >> m >> k;
    vector<int> a (n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    num res = 0;
    for (int i = 0; i < n; ++i) {
        int l = i+1;
        int r = upper_bound(a.begin(), a.end(), a[i]+k) - a.begin();
        if (m-1 <= r-l)
            res += fact[r-l] / fact[r-l-m+1] / fact[m-1];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i < 200005; ++i) {
        fact[i] = fact[i-1] * i;
    }
    mf = fact[m-1];
    while (t--)
        solve();
    return 0;
}
