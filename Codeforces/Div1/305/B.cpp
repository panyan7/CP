#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            l[i] = i - st.top();
        else
            l[i] = i + 1;
        st.push(i);
    }
    st = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            r[i] = st.top() - i;
        else
            r[i] = n - i;
        st.push(i);
    }
    vector<ll> res(n+1, 0);
    for (int i = 0; i < n; i++) {
        int max_range = l[i] + r[i] - 1;
        res[max_range] = max(res[max_range], a[i]);
    }
    for (int i = n-1; i >= 1; i--) {
        res[i] = max(res[i+1], res[i]);
    }
    for (int i = 1; i <= n; i++)
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
