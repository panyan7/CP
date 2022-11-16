#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

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
using num = ModNum<MOD>;
int tt = 1, n, m, k;

void solve() {
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> l(n+1);
    stack<int> st;
    vector<vector<num>> dp(n+1, vector<num>(m+1, 0));
    vector<vector<num>> p(n+1, vector<num>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        vector<int> pp;
        while (!st.empty() && a[st.top()] < a[i]) {
            int k = st.top();
            pp.push_back(k);
            st.pop();
        }
        for (int k = 0; k+1 < pp.size(); k++) {
            for (int j = 1; j <= m; j++) {
                dp[pp[k+1]][j] *= p[pp[k]][j];
                p[pp[k+1]][j] = p[pp[k+1]][j-1] + dp[pp[k+1]][j];
            }
        }
        if (pp.size() > 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = p[pp.back()][j-1];
            }
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = 1;
            }
        }
        for (int j = 1; j <= m; j++)
            p[i][j] = p[i][j-1] + dp[i][j];
        l[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    vector<int> pp;
    while (!st.empty()) {
        int k = st.top();
        pp.push_back(k);
        st.pop();
    }
    for (int k = 0; k+1 < pp.size(); k++) {
        for (int j = 1; j <= m; j++) {
            dp[pp[k+1]][j] *= p[pp[k]][j];
            p[pp[k+1]][j] = p[pp[k+1]][j-1] + dp[pp[k+1]][j];
        }
    }
    cout << p[pp.back()][m] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
