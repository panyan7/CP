#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

bool eq(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// check long long
void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> s;
    s.push_back(a);
    while (true) {
        vector<int> cnt(2001, 0);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cnt[a[i]]++;
        for (int i = 0; i < n; i++)
            b[i] = cnt[a[i]];
        if (eq(a, b))
            break;
        s.push_back(b);
        a = b;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        if (k >= s.size())
            k = s.size()-1;
        cout << s[k][x] << "\n";
    }
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
