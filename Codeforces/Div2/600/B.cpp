#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m;

void solve() {
    cin >> n;
    vector<int> a (n, 0);
    for (auto& x : a) cin >> x;
    set<int> s;
    vector<int> res;
    int l = -1;
    vector<bool> vst (1000001, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            if (s.find(a[i]) != s.end()) {
                cout << "-1\n";
                return;
            } else if (vst[a[i]]){
                cout << "-1\n";
                return;
            } else {
                s.insert(a[i]);
                vst[a[i]] = true;
            }
        } else {
            if (s.find(-a[i]) == s.end()) {
                cout << "-1\n";
                return;
            } else {
                s.erase(-a[i]);
            }
        }
        if (s.size() == 0) {
            res.push_back(i-l);
            l = i;
            vst.assign(1000001, false);
        }
    }
    if (s.size() != 0) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
