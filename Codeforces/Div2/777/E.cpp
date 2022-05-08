#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    int lim = ceil(log2(1e9)) + 1;
    set<int> st;
    vector<vector<int>> up(n, vector<int>(lim, 0));
    for (int i = 0; i < n; i++) {
        cin >> up[i][0];
        up[i][0]--;
        st.insert(up[i][0]);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    int num_rounds = (mx - n) / (n - (int)st.size());
    for (int j = 1; j < lim; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    vector<vector<int>> end_pos(n);
    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = 0; j < lim; j++) {
            if (num_rounds & (1 << j))
                p = up[p][j];
        }
        end_pos[p].push_back(i);
    }
    vector<int> res(n);
    set<int> pos;
    vector<vector<int>> all_pos(n+1);
    for (int i = 0; i < n; i++) {
        if (end_pos[i].size() > 0) {
            res[end_pos[i][0]] = a[i];
            all_pos[a[i]] = end_pos[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (all_pos[i].size() > 0) {
            for (int j = 1; j < all_pos[i].size(); j++)
                pos.insert(all_pos[i][j]);
        } else {
            int j = *pos.begin();
            res[j] = i;
            pos.erase(j);
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << "\n";
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
