#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

int dvc(vector<ll>& a, ll b) {
    if (b == 0)
        return a.size();
    if (a.size() <= 1)
        return a.size();
    vector<ll> one, zero;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] & (1LL << b))
            one.push_back(a[i]);
        else
            zero.push_back(a[i]);
    }
    int max_one = dvc(one, b-1);
    int max_zero = dvc(zero, b-1);
    int res = max(max_one, max_zero) + min(min(max_one, max_zero), 1);
    return res;
}

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<ll>());
    int res = dvc(a, 31);
    cout << n-res << "\n";
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
