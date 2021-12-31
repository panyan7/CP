#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;

// check long long
void solve() {
    cin >> n;
    string a, b;
    cin >> a >> b;
    string order;
    vector<int> res;
    for (int i = 0; i < n/2; i++) {
        order.push_back(a[i]);
        order.push_back(a[n-i-1]);
    }
    if (n % 2 == 1)
        order.push_back(a[n/2]);
    reverse(order.begin(), order.end());
    bool rev = false;
    for (int i = n-1; i >= 0; i--) {
        if (rev)
            order[i] = '1'-(order[i]-'0');
        rev = !rev;
        if (order[i] == b[i])
            res.push_back(1);
        res.push_back(i+1);
    }
    cout << res.size() << " ";
    for (int x : res)
        cout << x << " ";
    cout << "\n";
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
