#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n >> k >> q;
    k--;
    int m = n * (n-1) / 2;
    vector<array<int,2>> rem;
    vector<array<int,2>> mat;
    vector<bool> vis(m, 0);
    map<pii,int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            mp[{i,j}] = mat.size();
            mat.push_back({i,j});
        }
    }
    vector<int> scores(n, 0);
    for (int l = 0; l < q; l++) {
        int a, pa, b, pb;
        cin >> a >> pa >> b >> pb;
        a--, b--;
        scores[a] += pa;
        scores[b] += pb;
        vis[mp[{a,b}]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (i == k)
            continue;
        int a = i, b = k;
        if (b < a)
            swap(a, b);
        if (vis[mp[{a,b}]])
            continue;
        vis[mp[{a,b}]] = 1;
        scores[k] += 3;
        scores[i] += 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (!vis[mp[{i,j}]])
                rem.push_back({i,j});
        }
    }
    for (int i = 0; i < pow(3, rem.size()); i++) {
        vector<int> scores2 = scores;
        vector<int> mr(rem.size(), 0);
        int ii = i;
        for (int j = 0; j < rem.size(); j++) {
            mr[j] = (ii % 3);
            ii /= 3;
        }
        for (int j = 0; j < rem.size(); j++) {
            int a = rem[j][0], b = rem[j][1];
            if (mr[j] == 0) {
                scores2[a] += 3;
                scores2[b] += 0;
            } else if (mr[j] == 1) {
                scores2[a] += 1;
                scores2[b] += 1;
            } else {
                scores2[a] += 0;
                scores2[b] += 3;
            }
        }
        bool ok = true;
        for (int l = 0; l < n; l++) {
            if (l == k)
                continue;
            if (scores2[l] >= scores2[k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
