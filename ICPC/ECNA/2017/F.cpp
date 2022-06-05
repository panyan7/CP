#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
 
ll n, wn, wc = 0;
ll si[10001], par[10001];
vector<ll> tree[10001];
 
int dfs(int c, int p) {
    ll tot = 0;
    ll child = 0;
    par[c] = p;
    for (auto& a : tree[c]) {
        if (a == p) continue;
        ll t = dfs(a, c);
        tot += t*(n-1-t);
        child += t;
    } 
 
    tot += child*(n-1-child);
    if (wc < tot) {
        wc = tot;
        wn = c;
    }
 
    child++;
    si[c] = child;
    return child;
}
 
int main() {
    cin >> n;
    n++;
    for (int i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    dfs(0, 0);
 
    vector<ll> under;
    for (auto& a : tree[wn]) 
        if (a != par[wn]) under.push_back(si[a]);
 
    under.push_back(n-si[wn]);
 
    sort(under.begin(), under.end());
 
    ll res = under[under.size()-2]*under[under.size()-1];
 
    cout << wc/2 << " " << (wc/2-res) << "\n";
 
    return 0;
}
