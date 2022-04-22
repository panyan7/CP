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
    friend ModNum pow(ModNum& a, int e) {
        ModNum res = 1;
        while (e) {
            if (e % 2) res *= a;
            e /= 2;
            a *= a;
        }
        return res;
    }
};

const int MOD = 1e9+7;
using num = ModNum<MOD>;
ll t = 1, n, m, k, q;
vector<num> times, sum;

void solve() {
    vector<num> cnt(10, 0);
    cin >> n >> m;
    while (n != 0) {
        cnt[n % 10]++;
        n /= 10;
    }
    num res = 0;
    for (int i = 0; i < 10; i++) {
        num one = m-(9-i) < 0 ? 1 : sum[m-(9-i)];
        res += cnt[i] * one;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    times.resize(2e5+1);
    sum.resize(2e5+1);
    times[0] = 1;
    times[1] = 1;
    for (int i = 1; i <= 2e5; i++) {
        if (i + 9 <= 2e5)
            times[i+9] += times[i];
        if (i + 10 <= 2e5)
            times[i+10] += times[i];
    }
    num s = 0;
    for (int i = 0; i <= 2e5; i++) {
        s += times[i];
        sum[i] = s;
    }
    while (t--)
        solve();
    return 0;
}
