#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i+1);
    for (int i = 0; i < n; i++) {
        auto it = st.begin();
        if (*it == p[i] && st.size() != 1)
            it++;
        q[i] = *it;
        st.erase(it);
    }
    if (q[n-1] == p[n-1])
        swap(q[n-1], q[n-2]);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << "\n";
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
