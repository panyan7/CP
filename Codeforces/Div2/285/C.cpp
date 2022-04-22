#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
vector<vector<int>> adj;
vector<int> d, s;

struct cmp {
    bool operator()(int i, int j) const {
        if (d[i] == d[j])
            return i < j;
        return d[i] < d[j];
    }
};

// check long long
void solve() {
    cin >> n;
    d.assign(n, 0);
    s.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> d[i] >> s[i];
    set<int, cmp> st;
    for (int i = 0; i < n; i++)
        if (d[i] > 0)
            st.insert(i);
    vector<pii> edges;
    while (!st.empty()) {
        auto it = st.begin();
        int i = *it;
        //cout << i << "," << s[i] << " ";
        st.erase(s[i]);
        //for (int i = 0; i < n; i++)
        //    cout << s[i] << " ";
        //cout << "\n";
        st.erase(i);
        s[s[i]] ^= i;
        d[i]--;
        d[s[i]]--;
        if (d[s[i]] > 0)
            st.insert(s[i]);
        edges.push_back({i, s[i]});
    }
    cout << edges.size() << "\n";
    for (pii p : edges)
        cout << p.first << " " << p.second << "\n";
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
