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
int tt = 1, n, m, k;
num fact[5005];
int p[5005];
 
num choose(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] / fact[n-k] / fact[k];
}
 
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    int sm = 0;
    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            ones.push_back(i);
        p[i] = sm;
        sm += s[i]-'0';
    }
    p[n] = sm;
    num res = 1;
    if (k == 0 || (int)ones.size() < k) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i + k <= (int)ones.size(); i++) {
        int e = (i+k < (int)ones.size() ? ones[i+k] : n);
        int b = (i-1 >= 0 ? ones[i-1] : -1);
        int len = e - b - 1;
        res += choose(len, k)-1;
        //printf("(%d,%d):%d * %d\n", b+1, e-1, 1, (int)choose(len, k));
    }
    int sign = -1;
    for (int t = k-1; t >= max(k-1,1); t--) {
        for (int i = k-t; i + t <= (int)ones.size()-k+t; i++) {
            int len = ones[i+t] - ones[i-1] - 1;
            res += (choose(len, t)-1) * num(sign);
            //printf("(%d,%d):%d * %d\n", ones[i-1]+1, ones[i+t]-1, sign, (int)choose(len, t));
        }
        sign = -sign;
    }
    //res += num(sign);
    cout << res << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    fact[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fact[i] = fact[i-1] * i;
    }
    while (tt--)
        solve();
    return 0;
}
