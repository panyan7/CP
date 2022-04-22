#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
vector<ll> s;
bool vis[800005];
vector<ll> ans;

void dfs(ll v, ll mx) {
    if (v >= mx)
        return;
    vis[v] = true;
    ans.push_back(v);
    for (ll x : s) {
        if (!vis[x^v]) {
            dfs(x^v, mx);
            return;
        }
    }
}

// check long long
void solve() {
    cin >> n;
    ll r = 0;
    s.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        r |= s[i];
    }
    ll b = 0;
    while (r) {
        b++;
        r >>= 1;
    }
    ll z = 1LL << b;
    while (z >= 0) {
        dfs(0, z);
        if (ans.size() == z)
            break;
        z = ans.size();
        ans.clear();
        memset(vis, 0, sizeof(vis));
    }
    cout << log2(ans.size()) << "\n";
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
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
