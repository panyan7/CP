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
    int wc = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W')
            wc++;
        else
            bc++;
    }
    char a = 'W', b = 'B';
    if (bc % 2 != n % 2)
        swap(a, b);
    vector<int> ops;
    // set everything to b
    for (int i = 0; i < n-1; i++) {
        if (s[i] == a) {
            ops.push_back(i+1);
            s[i] = b;
            s[i+1] = (s[i+1] == b ? a : b);
        }
    }
    if (s[n-1] == a) {
        cout << "-1\n";
        return;
    }
    cout << ops.size() << "\n";
    for (int i = 0; i < (int)ops.size(); i++)
        cout << ops[i] << " \n"[i+1==(int)ops.size()];
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
