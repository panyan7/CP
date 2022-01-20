#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

ll tt = 1, n, m, k;
ll a[100005];
unordered_map<ll, ll> kf;
unordered_map<ll, ll> cnt[100005];

void factor_k(ll k) {
    while (k % 2 == 0) {
        kf[2]++;
        k /= 2;
    }
    for (ll i = 3; i <= sqrt(k); i += 2) {
        while (k % i == 0) {
            kf[i]++;
            k /= i;
        }
    }
    if (k > 2)
        kf[k]++;
}

void factor(int i) {
    ll x = a[i];
    for (auto p : kf) {
        cnt[i][p.first] = 0;
        while (x % p.first == 0) {
            cnt[i][p.first]++;
            x /= p.first;
        }
    }
}

// check long long
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    factor_k(k);
    for (int i = 1; i <= n; i++) {
        factor(i);
    }
    ll res = 0;
    unordered_map<ll, ll> cur;
    for (int i = 1, j = 1; i <= n; i++) {
        auto check = [&]() {
            for (auto p : kf) {
                if (cur[p.first] < p.second) {
                    return false;
                }
            }
            return true;
        };
        while (j <= n && !check()) {
            for (auto p : cnt[j]) {
                cur[p.first] += p.second;
            }
            j++;
        }
        j = max(j, i+1);
        //cout << j << " ";
        // can remove n-j
        ll to_add = n+1-j;
        if (check())
            to_add++;
        /*
        cout << i << " " << a[i] << " " << to_add << "\n";
        for (auto p : cur) {
            cout << p.first << " " << p.second << "\n";
        }
        */
        res += to_add;
        for (auto p : cnt[i])
            cur[p.first] -= p.second;
    }
    cout << res << "\n";
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
