#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
 
template <int MOD>
struct ModNum {
    int v;
    ModNum() : v(0) {}
    ModNum(int64_t v_) : v(int((v_ + MOD) % MOD)) {}
    explicit operator int() const { return v; }
    friend bool operator==(const ModNum& a, const ModNum& b) {
        return a.v == b.v;
    }
    friend bool operator!=(const ModNum& a, const ModNum& b) {
        return !(a == b);
    }
    static int minv(int a, int m) {
        if (a <= 1) return a;
        return m - int(int64_t(minv(m % a, a)) * m / a);
    }
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
};
const int MOD = 37;
using num = ModNum<MOD>;
 
int gauss(vector<vector<num>> a, vector<num> &ans) {
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (a[i][col].v > a[sel][col].v)
                sel = i;
        if (a[sel][col] == num(0))
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for (int i = 0; i < n; ++i)
            if (i != row) {
                num c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        num sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (sum != a[i][m])
            return 0;
    }
    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}
 
 
int main() {
    int n;
    cin >> n;
    string a, b;
    getline(cin, a);
    getline(cin, a);
    getline(cin, b);
    vector<int> a1, b1;
    auto char_to_int = [](char c) {
        if (c >= 'A' && c <= 'Z')
            return (int)(c-'A');
        if (c >= '0' && c <= '9')
            return (int)(c-'0')+26;
        return 36;
    };
    /*auto int_to_char = [](int x) {
        if (x < 26)
            return (char)('A' + x);
        if (x < 36)
            return (char)('0' + x-26);
        return ' ';
    };*/
    for (char c : a)
        a1.push_back(char_to_int(c));
    for (char c : b)
        b1.push_back(char_to_int(c));
    while (a1.size() % n != 0)
        a1.push_back(36);
    while (b1.size() % n != 0)
        b1.push_back(36);
    while (a1.size() < b1.size())
        a1.push_back(36);
    while (b1.size() < a1.size())
        b1.push_back(36);
    /*
    for (int i = 0; i < b1.size(); i++)
        cout << a1[i] << " ";
    cout << "\n";
    for (int i = 0; i < b1.size(); i++)
        cout << b1[i] << " ";
    cout << "\n";
    */
    vector<vector<num>> mat((int)b1.size(), vector<num>(n*n+1));
    for (int i = 0; i < (int)b1.size() / n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mat[i*n+j][j*n+k] = a1[i*n+k];
            }
            mat[i*n+j].back() = b1[i*n+j];
        }
    }
    vector<num> ans(n*n);
    int r = gauss(mat, ans);
    if (r == 2) {
        cout << "Too many solutions\n";
    } else if (r == 0) {
        cout << "No solution\n";
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i*n+j].v << " ";
            }
            cout << "\n";
        }
    }
}
