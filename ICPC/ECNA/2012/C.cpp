#include <bits/stdc++.h>
using namespace std;
using arr = array<int,6>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cc = 0;
    int tt = 0;
    cin >> tt;
    while (tt--) {
        cc++;
        vector<arr> a(7);
        vector<arr> vl(7);
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> a[i][j];
                vl[i][a[i][j]-1] = j;
            }
        }
        cout << "Case " << cc << ": ";
        bool exist_sol = false;
        vector<bool> vis(7,0);
        vector<int> mod(7,0);
        vector<int> idx;
        auto dfs = [&](auto dfs, int v, vector<bool>& vis, vector<int>& mod, vector<int>& idx) -> bool {
            int i = idx.size();
            vis[v] = true;
            idx.push_back(v);
            if (idx.size() == 1) {
                mod[0] = vl[idx[0]][0];
            } else {
                int center_val = a[idx[0]][(mod[0]+(i-1))%6];
                mod[i] = (vl[idx[i]][center_val-1]-(((i-1)+3)%6)+6)%6;
                if (i == 6) {
                    bool ok = true;
                    int cur_loc = ((i-1)+2)%6;
                    int nxt_loc = ((i-1)+2+3)%6;
                    if (a[idx[i]][(cur_loc+mod[i])%6] != a[idx[(i%6)+1]][(nxt_loc+mod[(i%6)+1])%6])
                        ok = false;
                    if (!ok) {
                        vis[v] = false;
                        idx.pop_back();
                        return false;
                    }
                }
                if (i > 1) {
                    bool ok = true;
                    i--;
                    int cur_loc = ((i-1)+2)%6;
                    int nxt_loc = ((i-1)+2+3)%6;
                    if (a[idx[i]][(cur_loc+mod[i])%6] != a[idx[(i%6)+1]][(nxt_loc+mod[(i%6)+1])%6])
                        ok = false;
                    if (!ok) {
                        vis[v] = false;
                        idx.pop_back();
                        return false;
                    }
                }
            }
            if (idx.size() == 7)
                return true;
            for (int u = 0; u < 7; u++) {
                if (!vis[u]) {
                    bool ok = dfs(dfs, u, vis, mod, idx);
                    if (ok)
                        return true;
                }
            }
            vis[v] = false;
            idx.pop_back();
            return false;
        };

        for (int center = 0; center < 7; center++) {
            bool ok = dfs(dfs, center, vis, mod, idx);
            if (ok) {
                exist_sol = true;
                break;
            }
        }
        if (exist_sol) {
            for (int i = 0; i < 7; i++)
                cout << idx[i] << " ";
            cout << "\n";
        } else {
            cout << "No solution\n";
        }
    }
}
