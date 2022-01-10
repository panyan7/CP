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
int s[5005], f[5005], h[5005];
int hp[5005][5005];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++)
        cin >> f[i] >> h[i];
    vector<multiset<int>> lc(n+1);
    vector<multiset<int,greater<int>>> rc(n+1);
    for (int i = 1; i <= n; i++) {
        lc[s[i]].insert(i);
        rc[s[i]].insert(i);
    }
    for (int i = 1; i <= m; i++)
        hp[f[i]][h[i]]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            hp[i][j] = hp[i][j-1] + hp[i][j];
    vector<num> res(m+1, 0);
    int best_num = 0;
    for (int l = 0; l <= n; l++) {
        int lclsl = distance(lc[s[l]].begin(), lc[s[l]].upper_bound(l));
        if (l > 0 && hp[s[l]][lclsl] - hp[s[l]][lclsl-1] == 0)
            continue;
        int cnt = 0;
        num total = 1;
        for (int c = 1; c <= n; c++) {
            if (c == s[l]) {
                int left_ub = distance(lc[c].begin(), lc[c].upper_bound(l));
                int right_ub = distance(rc[c].begin(), rc[c].upper_bound(l+1));
                int left_choice = hp[c][left_ub];
                if (left_ub > 0)
                    left_choice -= hp[c][left_ub-1];
                int right_choice = hp[c][right_ub];
                cnt++;
                if (right_ub >= left_ub) {
                    if (right_choice > 1) {
                        cnt++;
                        right_choice--;
                    } else {
                        right_choice = 1;
                    }
                } else {
                    if (right_choice > 0) {
                        cnt++;
                    } else {
                        right_choice = 1;
                    }
                }
                total *= num(left_choice) * num(right_choice);
            } else {
                int left_ub = distance(lc[c].begin(), lc[c].upper_bound(l));
                int right_ub = distance(rc[c].begin(), rc[c].upper_bound(l+1));
                int left_choice = hp[c][left_ub];
                int right_choice = hp[c][right_ub];
                if (right_ub < left_ub) {
                    swap(left_ub, right_ub);
                    swap(left_choice, right_choice);
                }
                if (left_choice > 0) {
                    cnt++;
                    right_choice--;
                    if (right_choice == 0)
                        left_choice *= 2;
                } else {
                    left_choice = 1;
                }
                if (right_choice > 0) {
                    cnt++;
                } else {
                    right_choice = 1;
                }
                total *= num(left_choice) * num(right_choice);
            }
        }
        res[cnt] += total;
        if (cnt > best_num)
            best_num = cnt;
    }
    cout << best_num << " " << res[best_num] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
