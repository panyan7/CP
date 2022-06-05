#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
ll a[55][55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // vector<pair<int,pair<int,int>>> p;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            //p.push_back({a[i][j], {i, j}});
            if (a[i][j] != -1)
                p.push_back(a[i][j]);
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    vector<unordered_set<int>> st(n+m-1);

    int k = 0;
    int res = INT_MAX;
    int cur = 0;
    for (int s = 0; s < n+m-1; s++) {
        for (int i = 0; i < n; i++) {
            int j = s - i;
            if (j < 0 || j >= m)
                continue;
            if (a[i][j] != -1) {
                st[s].insert(p[k]);
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                if (st[i+j].count(a[i][j]) == 0)
                    cur++;
            }
        }
    }
    res = min(res, cur);

    st.clear();
    st.resize(n+m-1);
    k = 0;
    for (int s = 0; s < n+m-1; s++) {
        for (int i = 0; i < n; i++) {
            int j = m - (s - i) - 1;
            if (j < 0 || j >= m)
                continue;
            if (a[i][j] != -1) {
                st[s].insert(p[k]);
                k++;
            }
        }
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                if (st[i+(m-j-1)].count(a[i][j]) == 0)
                    cur++;
            }
        }
    }
    res = min(res, cur);

    st.clear();
    st.resize(n+m-1);
    k = 0;
    for (int s = 0; s < n+m-1; s++) {
        for (int i = 0; i < n; i++) {
            int j = s - (n-i-1);
            if (j < 0 || j >= m)
                continue;
            if (a[i][j] != -1) {
                st[s].insert(p[k]);
                k++;
            }
        }
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                if (st[(n-i-1)+j].count(a[i][j]) == 0)
                    cur++;
            }
        }
    }
    res = min(res, cur);

    st.clear();
    st.resize(n+m-1);
    k = 0;
    for (int s = 0; s < n+m-1; s++) {
        for (int i = 0; i < n; i++) {
            int j = m - (s - (n-i-1)) - 1;
            if (j < 0 || j >= m)
                continue;
            if (a[i][j] != -1) {
                st[s].insert(p[k]);
                k++;
            }
        }
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1) {
                if (st[(n-i-1)+(m-j-1)].count(a[i][j]) == 0)
                    cur++;
            }
        }
    }
    res = min(res, cur);



    cout << res << "\n";

    return 0;
}

