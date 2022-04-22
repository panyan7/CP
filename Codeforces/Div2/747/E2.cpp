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
    friend ModNum pow(const ModNum& a, ll e) {
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
ll t = 1, n, m, k, q;
unordered_map<ll, array<num,6>> dp;

void solve() {
    cin >> k;
    cin >> n;
    unordered_map<ll, ll> mp;
    set<ll> marked;
    for (int i = 0; i < n; i++) {
        ll v; string s;
        cin >> v >> s;
        if (s == "white")
            mp[v] = 0;
        else if (s == "yellow")
            mp[v] = 3;
        else if (s == "green")
            mp[v] = 1;
        else if (s == "blue")
            mp[v] = 4;
        else if (s == "red") 
            mp[v] = 2;
        else
            mp[v] = 5;

        ll u = v;
        while (u) {
            marked.insert(u);
            u >>= 1;
        }
    }
    vector<ll> mark_list;
    for (ll v : marked)
        mark_list.push_back(v);
    reverse(mark_list.begin(), mark_list.end());
    for (ll v : mark_list) {
        dp[v] = {};
        if (mp.find(v) != mp.end()) {
            // is colored
            if (2 * v >= (1LL << k)) {
                dp[v][mp[v]] = 1;
                continue;
            }
            num l = 0, r = 0;
            if (marked.find(2*v) == marked.end())
                l = 1;
            else
                for (int c = 0; c < 6; c++)
                    if (c % 3 != mp[v] % 3)
                        l += dp[v*2][c];
            if (marked.find(2*v+1) == marked.end())
                r = 1;
            else
                for (int c = 0; c < 6; c++)
                    if (c % 3 != mp[v] % 3)
                        r += dp[v*2+1][c];
            dp[v][mp[v]] = l * r;
            continue;
        }
        // not colored
        if (2 * v >= (1LL << k)) {
            for (int c = 0; c < 6; c++)
                dp[v][c] = 1;
            continue;
        }
        //assert(2 * v < (1LL << k));
        for (int d = 0; d < 6; d++) {
            num l = 0, r = 0;
            if (marked.find(2*v) == marked.end())
                l = 1;
            else
                for (int c = 0; c < 6; c++)
                    if (c % 3 != d % 3)
                        l += dp[v*2][c];
            if (marked.find(2*v+1) == marked.end())
                r = 1;
            else
                for (int c = 0; c < 6; c++)
                    if (c % 3 != d % 3)
                        r += dp[v*2+1][c];
            dp[v][d] = l * r;
        }
    }
    num res = 0;
    for (int c = 0; c < 6; c++)
        res += dp[1][c];
    cout << res * pow(num(4), (1LL << k) - (ll)marked.size() - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
