#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k, q;

void solve() {
    cin >> n >> q;
    set<pii> st;
    int work_days = n;
    st.insert({n, 1});
    for (int i = 0; i < q; i++) { int l, r, k;
        cin >> l >> r >> k;
        if (k & 1) {
            auto it1 = st.lower_bound({l, 0});
            auto it2 = st.lower_bound({r, 0});
            bool erase_it2 = false;
            for (auto it = it1; ; it++) {
                if (it == st.end())
                    break;
                if (it->second > r)
                    break;
                work_days -= it->first - it->second + 1;
                if (l-1 >= it->second) {
                    st.insert({l-1, it->second});
                    work_days += (l-1) - it->second + 1;
                }
                if (it->first >= r+1) {
                    st.insert({it->first, r+1});
                    work_days += it->first - (r+1) + 1;
                }
                if (it == it2) {
                    erase_it2 = true;
                    break;
                }
            }
            if (erase_it2)
                it2++;
            st.erase(it1, it2);
        } else {
            auto it1 = st.lower_bound({l, 0});
            auto it2 = st.lower_bound({r, 0});
            bool erase_it2 = false;
            for (auto it = it1; ; it++) {
                if (it == st.end())
                    break;
                if (it->second > r)
                    break;
                work_days -= it->first - it->second + 1;
                l = min(it->second, l);
                r = max(it->first, r);
                if (it == it2) {
                    erase_it2 = true;
                    break;
                }
            }
            if (erase_it2)
                it2++;
            st.erase(it1, it2);
            st.insert({r, l});
            work_days += r - l + 1;
        }
        // for (auto p : st)
            // cout << p.first << "," << p.second << " ";
        cout << work_days << "\n";
    }
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
