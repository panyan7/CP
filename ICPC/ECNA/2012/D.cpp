#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cc = 0;
    map<array<int,6>,int> mp;
    vector<array<int,6>> conf;
    auto dfs = [&](auto dfs, int rem, int level, array<int,6> cur_conf) {
        if (level == 5) {
            cur_conf[level] = rem;
            mp[cur_conf] = conf.size();
            conf.push_back(cur_conf);
            return;
        }
        for (int i = 0; i <= rem; i++) {
            cur_conf[level] = i;
            dfs(dfs, rem-i, level+1, cur_conf);
        }
    };
    dfs(dfs, 15, 0, {0,0,0,0,0,0});
    while (true) {
        cc++;
        char c;
        cin >> c;
        if (c == 'e')
            break;
        if (c == 'm') {
            array<int,6> cur_conf;
            for (int i = 0; i < 6; i++)
                cin >> cur_conf[i];
            cout << "Case " << cc << ": " << mp[cur_conf] << "\n";
        } else if (c == 'u') {
            int j; cin >> j;
            auto& cur_conf = conf[j];
            cout << "Case " << cc << ": ";
            for (int i = 0; i < 6; i++)
                cout << cur_conf[i] << " ";
            cout << "\n";
        }
    }
}
