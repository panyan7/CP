#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

ll dvc(vector<ll>& a, ll b) {
    if (a.size() <= 1)
        return 0;
    if (b == 0) {
        bool same = true;
        for (int i = 1; i < (int)a.size(); i++) {
            if ((a[i] & 1LL) != (a[i-1] & 1LL))
                same = false;
        }
        return (same ? 0LL : 1LL);
    }
    vector<ll> one, zero;
    for (int i = 0; i < (int)a.size(); i++) {
        if ((a[i] & (1LL << b)))
            one.push_back(a[i]);
        else
            zero.push_back(a[i]);
    }
    if (one.size() == 0)
        return dvc(zero, b-1);
    if (zero.size() == 0)
        return dvc(one, b-1);
    ll res_one = dvc(one, b-1);
    ll res_zero = dvc(zero, b-1);
    return (1LL << b) + min(res_one, res_zero);
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    cout << dvc(a, 29) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
