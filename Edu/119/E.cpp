#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int mp[500005];

int find_mp(int v) {
    if (mp[v] == v)
        return v;
    return mp[v] = find_mp(mp[v]);
}

// check long long
void solve() {
    for (int i = 0; i <= 500000; i++)
        mp[i] = i;
    cin >> n;
    vector<array<int,2>> query;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            query.push_back({-1, x});
            cnt++;
        } else {
            int x, y; cin >> x >> y;
            query.push_back({x, y});
        }
    }
    vector<int> res(cnt, 0);
    int j = cnt-1;
    for (int i = n-1; i >= 0; i--) {
        if (query[i][0] == -1) {
            res[j] = mp[query[i][1]];
            j--;
        } else {
            //mp[query[i][0]] = find_mp(query[i][1]);
            mp[query[i][0]] = mp[query[i][1]];
        }
    }
    for (int i = 0; i < cnt; i++)
        cout << res[i] << " \n"[i+1==cnt];
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
