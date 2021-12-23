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
ll a[200010];
num dp[200010][2], p[200010][2];
vector<int> st;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = a[1];
    p[0][0] = 1;
    p[0][1] = 0;
    p[1][0] = 1;
    p[1][1] = a[1];
    st.push_back(0);
    st.push_back(1);
    a[0] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        while (st.size() > 0 && a[st.back()] >= a[i]) {
            int j = st.back();
            st.pop_back();
            // st.back() to j-1 needs to be updated
            // originally was calculated using a[j], now should be using a[i]
            dp[i][0] = dp[i][0] + (p[j-1][1] - p[st.back()-1][1]) * (a[i] - a[j]);
            dp[i][1] = dp[i][1] + (p[j-1][0] - p[st.back()-1][0]) * (a[i] - a[j]);
        }
        st.push_back(i);
        dp[i][0] += dp[i-1][1] * a[i];
        dp[i][1] += dp[i-1][0] * a[i];
        p[i][0] = p[i-1][0] + dp[i][0];
        p[i][1] = p[i-1][1] + dp[i][1];
    }
    num res = dp[n][1] - dp[n][0];
    if (n % 2 == 0)
        res = 0 - res;
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
