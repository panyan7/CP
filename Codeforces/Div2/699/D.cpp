#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int t = 1, n, m, k;
vector<string> adj;

void solve() {
    cin >> n >> m;
    adj.resize(n);
    for (auto& s : adj)
        cin >> s;
    if (m % 2 == 1) {
        cout << "YES\n";
        for (int i = 0; i < m+1; i++) {
            if (i % 2) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
        return;
    }
    bool can = false;
    int id1, id2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (adj[i][j] == adj[j][i]) {
                can = true;
                id1 = i;
                id2 = j;
            }
        }
    }
    if (can) {
        cout << "YES\n";
        for (int i = 0; i < m+1; ++i) {
            if (i % 2)
                cout << id1+1 << " ";
            else
                cout << id2+1 << " ";
        }
        cout << "\n";
        return;
    }
    int midid;
    for (int i = 0; i < n; ++i) {
        bool hasa = false, hasb = false;
        int ida, idb;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (adj[i][j] == 'a') {
                hasa = true;
                ida = j;
            }
            if (adj[i][j] == 'b') {
                hasb = true;
                idb = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (adj[j][i] == 'a' && hasa) {
                can = true;
                midid = i;
                id2 = ida;
                id1 = j;
            }
            if (adj[j][i] == 'b' && hasb) {
                can = true;
                midid = i;
                id2 = idb;
                id1 = j;
            }
        }
    }
    if (can) {
        cout << "YES\n";
        assert(id1 != id2);
        assert(midid != id1);
        assert(midid != id2);
        assert(adj[id1][midid] == adj[midid][id2]);
        ++id1, ++id2, ++midid;
        for (int i = 0; i < m/2; ++i) {
            if ((i % 2) == ((m/2) % 2))
                cout << id2 << " ";
            else
                cout << id1 << " ";
        }
        cout << midid << " ";
        for (int i = 0; i < m/2; ++i) {
            if ((m/2) % 2 == 1) {
                if ((i % 2) == ((m/2) % 2))
                    cout << id1 << " ";
                else
                    cout << id2 << " ";
            } else {
                if ((i % 2) == ((m/2) % 2))
                    cout << id2 << " ";
                else
                    cout << id1 << " ";
            }
        }
        cout << "\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
