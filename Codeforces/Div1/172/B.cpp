#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    stack<ll> st;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();
        if (!st.empty())
            res = max(res, st.top() ^ a[i]);
        st.push(a[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();
        if (!st.empty())
            res = max(res, st.top() ^ a[i]);
        st.push(a[i]);
    }
    cout << res << "\n";
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
