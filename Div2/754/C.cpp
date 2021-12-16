#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            a.push_back(i);
    }
    if (a.size() < 2) {
        cout << "-1\n";
        return;
    }
    int res = INT_MAX;
    for (int i = 0; i < (int)a.size()-1; i++) {
        if (a[i+1]-a[i] <= 2)
            res = min(res, a[i+1]-a[i]+1);
        else if (a[i+1]-a[i] == 3) {
            if (s[a[i]+1] != s[a[i]+2])
                res = min(res, 4);
        }
    }
    for (int i = 0; i < (int)a.size()-2; i++) {
        string b = s.substr(a[i], 7);
        int cntb = 0;
        for (int j = 0; j < b.size(); j++)
            if (b[j] == 'b')
                cntb++;
        if (b[0] == 'a' && b[3] == 'a' && b[6] == 'a' && cntb == 2)
            res = min(res, 7);
    }
    if (res == INT_MAX)
        res = -1;
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
