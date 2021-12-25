#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, res = 0;
    while (i < n) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        if (j >= n) {
            res = max(res, j-i);
            break;
        }
        int k = j, cnt = j-i+1;
        if (i < n) {
            ll d = a[j] - a[i];
            d *= 2;
            while (true) {
                auto it = lower_bound(a.begin(), a.end(), a[i] + d);
                if (it == a.end())
                    break;
                k = it - a.begin();
                d = a[k] - a[i];
                d *= 2;
                cnt++;
            }
        }
        res = max(res, cnt);
        i = j;
    }
    cout << n-res << "\n";
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
