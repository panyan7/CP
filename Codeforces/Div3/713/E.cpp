#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;

void solve() {
    int l, r, s;
    cin >> n >> l >> r >> s;
    set<int> st;
    r--, l--;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int sz = r-l+1;
    if (s < (1 + sz) * sz / 2 || s > (2 * n - sz + 1) * sz / 2)
        cout << "-1\n";
    else {
        vector<int> res(n);
        if (sz % 2 == 1) {
            int avg = s / sz;
            int rem = s % sz;
            for (int i = l; i <= r; i++) {
                res[i] = avg + (i - l) - (sz - 1) / 2;
                if (i + rem > r)
                    res[i]++;
                st.erase(res[i]);
            }
        } else {
            int avg = (s * 2 / sz - 1) / 2;
            int rem = s - (2 * avg + 1) * sz / 2;
            for (int i = l; i <= r; i++) {
                res[i] = avg + (i - l) - (sz - 1) / 2;
                if (i + rem > r)
                    res[i]++;
                st.erase(res[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (res[i] == 0) {
                auto it = st.begin();
                res[i] = *it;
                st.erase(it);
            }
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
