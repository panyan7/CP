#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        string s(n, '1');
        s[i] = '0';
        cout << "? " << i+1 << " " << s << "\n";
        cout.flush();
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pii>());
    int last = 0;
    for (int i = 1; i < n; i++) {
        string s(n, '0');
        for (int j = 0; j <= last; j++) {
            s[a[j].second] = '1';
        }
        cout << "? " << a[i].second+1 << " " << s << "\n";
        cout.flush();
        int x; cin >> x;
        if (x > 0)
            last = i;
    }
    string res(n, '0');
    for (int i = 0; i <= last; i++) {
        res[a[i].second] = '1';
    }
    cout << "! " << res << "\n";
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
