#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

template<class T_in, class T_out>
vector<T_out> zeta_transform(vector<T_in>& a) {
    assert(a.size() == (1 << n));
    vector<T_out> f(1 << n);
    for (int i = 0; i < (1 << n); i++)
        f[i] = a[i];
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i))
                f[mask] += f[mask^(1<<i)];
        }
    }
    return f;

}

// check long long
void solve() {
    n = 24;
    cin >> m;
    vector<int> vowel(1 << n, 0);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (char c : s)
            mask |= (1 << (int)(c-'a'));
        vowel[mask]++;
    }
    vector<int> f = zeta_transform<int,int>(vowel);
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        f[i] = m-f[i];
        ans ^= (ll)f[i] * f[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
