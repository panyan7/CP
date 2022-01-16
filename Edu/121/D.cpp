#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> num(n+2, 0);
    vector<ll> pref(n+2, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        num[x]++;
    }
    //unordered_map<int, int> mp;
    for (int i = 1; i <= n+1; i++) {
        pref[i] = pref[i-1] + num[i];
    }
    ll u = log2(n)+1;
    ll cost = LLONG_MAX;
    vector<ll> ld(u+2, 0), rd(u+2, n+1);
    int l = 0, r = n+1;
    for (ll i = -1; i <= u; i++) {
        ll nl = (i == -1 ? 0 : (1LL << i));
        while (l <= n && pref[l] - pref[0] <= nl) {
            l++;
        }
        l--;
        ld[i+1] = l;
    }
    for (ll j = -1; j <= u; j++) {
        ll nr = (j == -1 ? 0 : (1LL << j));
        while (r >= 0 && pref[n+1] - pref[r] <= nr) {
            r--;
        }
        r++;
        rd[j+1] = r;
    }
    for (ll i = -1; i <= u; i++) {
        for (ll j = -1; j <= u; j++) {
            ll nl = (i == -1 ? 0 : (1LL << i));
            ll nr = (j == -1 ? 0 : (1LL << j));
            l = ld[i+1], r = rd[j+1];
            if (l >= r)
                break;
            ll nm = n - (pref[n+1] - pref[r]) - (pref[l] - pref[0]);
            nm = 1LL << (ll)ceil(log2(nm));
            nm = max(nm, 1LL);
            nl = max(nl, 1LL);
            nr = max(nr, 1LL);
            //printf("l:%d, r:%d, nl:%d, nr:%d, nm:%d, cost:%d\n", l, r, nl, nr, nm, nl+nr+nm-n);
            cost = min(cost, nl + nr + nm - n);
        }
    }
    cout << cost << "\n";
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
