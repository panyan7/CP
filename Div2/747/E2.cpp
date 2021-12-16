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

const int MOD = 1e9+7;
using num = ModNum<MOD>;
int t = 1, n, m, k, q;

void solve() {
    cin >> k;
    vector<num> dp(k+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 16 * dp[i-1] * dp[i-1];
    }
    // dp i == (k-i)th layer, fix root, number of ways
    cin >> n;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        int v; string s;
        cin >> v >> s;
        if (s == "white" || s == "yellow")
            mp[v] = 0;
        else if (s == "green" || s == "blue")
            mp[v] = 1;
        else
            mp[v] = 2;
    }
    map<ll, array<num,3>> d;
    for (int i = 1; i <= k; i++) {
        for (auto p : mp) {
            if (p.first >= (1LL << (k-i)) && p.first < (1LL << (k-i+1))) {
                ll p1 = p.first;
                ll p2 = p.first ^ 1LL;
                ll pa = p.first >> 1LL;
                bool isp2 = (mp.find(p2) != mp.end());
                bool ispa = (mp.find(pa) != mp.end());
                if (ispa) {
                    if (isp1) {
                        if (mp[pa] == mp[p1]) {
                            cout << "0\n";
                            return;
                        }
                        if (mp[p2] == mp[p1]) {
                            d[pa] = {0,0,0};
                            for (int j = 0; j < 3; j++) {
                                if (j != mp[p2]) {
                                    d[pa][j] = d[p1][mp[p1]]
                                } else {
                                    d[pa][j] = 
                                }
                            }
                        } else {

                        }
                    } else {

                    }
                } else {
                    if (isp1) {

                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
