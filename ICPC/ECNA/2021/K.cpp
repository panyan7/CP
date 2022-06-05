#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int h, w;
int dg[10010], d1[10010], d2[10010];
int table[100][100];
bool visited[10010];
set<int> g[10010], gr[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> table[i][j];

    for (int i = 0; i < h-1; i++) {
        for (int j = 0; j < w; j++) {
            g[table[i+1][j]].insert(table[i][j]);
            gr[table[i][j]].insert(table[i+1][j]);
        }
    }

    for (int j = 0; j < w; j++) {
        g[0].insert(table[h-1][j]);
        gr[table[h-1][j]].insert(0);
    }

    for (int i = 0; i < h*w+1; i++) {
        dg[i] = 10000000;
        d1[i] = 10000000;
        d2[i] = 10000000;
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    dg[0] = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (auto& a : g[c]) {
            if (visited[a]) continue;
            visited[a] = true;
            dg[a] = dg[c]+1;
            q.push(a);
        }
    }

    bool single = true;
    int top1 = table[0][0], top2 = 0;
    for (int j = 0; j < w-1; j++) {
        if (table[0][j] != table[0][j+1]) {
            single = false;
            top1 = table[0][j];
            top2 = table[0][j+1];
        }
    }

    for (int i = 0; i < h*w+1; i++) visited[i] = false;

    q.push(top1);
    visited[top1] = true;
    d1[top1] = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        for (auto& a : gr[c]) {
            if (visited[a]) continue;
            visited[a] = true;
            d1[a] = d1[c]+1;
            q.push(a);
        }
    }

    int res = 100000000;
    if (single) res = dg[top1];
    else {
        for (int i = 0; i < h*w+1; i++) visited[i] = false;

        q.push(top2);
        visited[top2] = true;
        d2[top2] = 0;
        while (!q.empty()) {
            int c = q.front();
            q.pop();

            for (auto& a : gr[c]) {
                if (visited[a]) continue;
                visited[a] = true;
                d2[a] = d2[c]+1;
                q.push(a);
            }
        }

        for (int i = 0; i < h*w+1; i++)
            res = min(res, dg[i]+d1[i]+d2[i]);
    }

    cout << res << endl;

    return 0;
}

