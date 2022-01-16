#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m;
ll k[105], h[105];

// check long long
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    ll mn = 0, d = 0, t = 0;
    //mn += h[1] * (h[1] + 1) / 2;
    //d = h[1];
    stack<pll> st;
    st.push({k[1], h[1]});
    for (int i = 2; i <= n; i++) {
        ll d = h[i];
        while (!st.empty() && k[i]-st.top().first < h[i]) {
            pll p = st.top();
            st.pop();
            d = max(d, p.second + k[i]-p.first);
        }
        st.push({k[i], d});
    }
    while (!st.empty()) {
        pll p = st.top();
        //cout << p.first << "," << p.second << " ";
        mn += p.second * (p.second + 1) / 2;
        st.pop();
    }
    cout << mn << "\n";
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
