#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

void solve() {
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d;
    cin >> s;
    n = s.size();
    int na = 0, nb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            na++;
        else
            nb++;
    }
    if (na != a+c+d || nb != b+c+d) {
        cout << "NO\n";
        return;
    }
    vector<int> as, bs, os;
    int i = 0;
    while (i < n) {
        int j = i+1;
        while (j < n && s[j] != s[j-1])
            j++;
        if (j-i != 1) {
            if ((j-i) % 2 == 1) {
                os.push_back(j-i);
            } else {
                if (s[i] == 'A')
                    as.push_back(j-i);
                else
                    bs.push_back(j-i);
            }
        }
        i = j;
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int ac = 0, bc = 0, oc = 0;
    for (int x : os)
        oc += x/2;
    for (int x : as)
        ac += x/2;
    for (int x : bs)
        bc += x/2;
    if (ac > c && bc <= d) {
        while (ac > c) {
            ac -= as.back() / 2;
            bc += as.back() / 2 - 1;
            as.pop_back();
        }
    } else if (ac <= c && bc > d) {
        while (bc > d) {
            bc -= bs.back() / 2;
            ac += bs.back() / 2 - 1;
            bs.pop_back();
        }
    }
    bool ok = (ac + bc + oc >= c+d);
    cout << (ok ? "YES\n" : "NO\n");
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
