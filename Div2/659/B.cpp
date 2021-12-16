#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(c) (c).begin(), (c).end()

int t, n, m, k, l;

void solve() {
    cin >> n >> k >> l;
    vector<int> d (n);
    for (auto& x : d) cin >> x;
    int kl = -k, kh = k-1;
    vector<int> km (n), sf (0);
    for (int i = 0; i < n; ++i) {
        km[i] = min(k, l-d[i]);
        if (km[i] == k)
            sf.push_back(i);
    }
    sf.push_back(n);
    int i = -1;
    for (auto& j : sf) {
        int tmin = -k, tmax = k;
        for (int a = i+1; a < j; ++a) {
            tmin = max(tmin+1, -km[a]);
            tmax = min(tmax+1, km[a]);
            // cout << a << ": " << km[a] << " " << tmin << " " << tmax << "\n";
            if (tmin > tmax) {
                cout << "No\n";
                return;
            }
        }
        i = j;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
