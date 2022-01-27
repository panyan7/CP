#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<pll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    // buy i people, 
    ll res = 0, cnt = 0;
    priority_queue<pll, vector<pll>, greater<pll>> st; // set of people that cannot be selected
    priority_queue<ll> st1; // set of people just to keep total number good
    for (int i = 0; i < n; i++) {
        bool inserted = false;
        if (a[i].first > i) {
            // need to add this
            if (!st1.empty()) {
                st1.pop();
            }
            // if at some time we have cnt' in total added,
            // we want a[i].first - i <= cnt' - cnt, so we need
            // to keep a priority queue with this quantity
            st.push({a[i].first - i + cnt, a[i].second});
            inserted = true;
            cnt++;
        } 
        while (!st.empty() && st.top().first <= cnt) {
            st1.push(st.top().second);
            st.pop();
        }
        if (a[i].first <= i) {
            if (!st1.empty() && st1.top() > a[i].second) {
                st1.pop();
                st1.push(a[i].second);
            }
        }
    }
    while (!st.empty()) {
        auto p = st.top();
        st.pop();
        res += p.second;
    }
    while (!st1.empty()) {
        ll p = st1.top();
        st1.pop();
        res += p;
    }
    cout << res << "\n";
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
