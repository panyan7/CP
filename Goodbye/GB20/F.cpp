#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int t;
vector<int> s[500005];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        int x[k+1];
        for (int j = 1; j <= k; ++j) {
            cin >> x[j];
        }
        int id = x[1], fp = 0;
        while (id <= m) {
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size()-1 ? "\n" : " ");
    }
    return 0;
}
