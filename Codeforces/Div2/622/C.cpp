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
    vector<ll> l(n), r(n);
    stack<pll> st;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = 1;
        while (!st.empty() && st.top().first > a[i]) {
            total -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        total += cnt * a[i];
        st.push({a[i], cnt});
        l[i] = total;
    }
    total = 0;
    st = stack<pll>();
    for (int i = n-1; i >= 0; i--) {
        ll cnt = 1;
        while (!st.empty() && st.top().first > a[i]) {
            total -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        total += cnt * a[i];
        st.push({a[i], cnt});
        r[i] = total;
    }
    ll best = 0, id = 0;
    for (int i = 0; i < n; i++) {
        ll s = l[i] + r[i] - a[i];
        if (s > best) {
            best = s;
            id = i;
        }
    }
    vector<ll> res;
    st = stack<pll>();
    for (int i = 0; i <= id; i++) {
        ll cnt = 1;
        while (!st.empty() && st.top().first > a[i]) {
            total -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        total += cnt * a[i];
        st.push({a[i], cnt});
    }
    while (!st.empty()) {
        pll p = st.top();
        for (int i = 0; i < p.second; i++)
            res.push_back(p.first);
        st.pop();
    }
    reverse(res.begin(), res.end());
    res.pop_back();
    st = stack<pll>();
    for (int i = n-1; i >= id; i--) {
        ll cnt = 1;
        while (!st.empty() && st.top().first > a[i]) {
            total -= st.top().first * st.top().second;
            cnt += st.top().second;
            st.pop();
        }
        total += cnt * a[i];
        st.push({a[i], cnt});
    }
    while (!st.empty()) {
        pll p = st.top();
        for (int i = 0; i < p.second; i++)
            res.push_back(p.first);
        st.pop();
    }
    assert(res.size() == n);
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
