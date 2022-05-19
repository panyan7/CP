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
num fact[200005];
 
 
num choose(ll a, ll b) {
    if (b < 0)
        return 0;
    if (b > a)
        return 0;
    return fact[a] / fact[b] / fact[a-b];
}
 
 
void solve() {
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = fact[i-1] * i;
    }
    int h, w;
    cin >> h >> w >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    a.push_back({h, w});
    n++;
    
    num res = 0;
    vector<num> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = choose(a[i].first+a[i].second-2, a[i].first-1);
        for (int j = 0; j < i; j++) {
            if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
                dp[i] -= choose(a[i].first+a[i].second-a[j].first-a[j].second, a[i].first-a[j].first) * dp[j];
            }
        }
    }
    cout << dp[n-1] << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
