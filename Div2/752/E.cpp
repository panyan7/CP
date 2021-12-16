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
 
const int MOD = 998244353;
using num = ModNum<MOD>;
int t = 1, n, m, k, q;
 
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    num res = 0;
    vector<vector<pii>> dp(n);
    // number after, extreme value+1, num times
    dp[n-1].push_back({a[n-1],1});
    for (int i = n-2; i >= 0; i--) {
        //cout << a[i] << "------\n";
        set<int, greater<int>> fct;
        for (int j = 1; j <= ceil(sqrt(a[i])); j++) {
            int k = (a[i] + j - 1) / j;
            fct.insert(j);
            fct.insert(k);
            //cout << j << " " << k << "\n";
        }
        vector<int> f;
        for (auto x : fct)
            f.push_back(x);
        int j = 0;
        unordered_map<int,int> mp;
        for (auto p : dp[i+1]) {
            assert(dp[i+1].size() <= 4 * sqrt(100000));
            int k = p.first;
            while (j < f.size() && f[j] > k)
                j++;
            int cnt = (a[i]+f[j]-1)/f[j];
            //assert(fct.find(cnt) != fct.end());
            // cnt must also be in the set fct
            //cout << nm << " " << cnt << "\n";
            mp[a[i]/cnt] += p.second;
            res += num(p.second) * num(cnt-1) * num(i+1);
        }
        mp[a[i]]++;
        for (auto p : mp)
            dp[i].push_back(p);
        sort(dp[i].begin(), dp[i].end(), greater<pii>());
        //for (auto p : cur)
            //printf("%d %d\n", p.first, p.second);
    }
    cout << res << "\n";
    cout << "NO\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
