#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll bin[100000], s[100000], arr[100000], l[100000], r[100000];
map<int, vector<int> > m;

int find(int v) {
    if (v == arr[v]) return v;
    return arr[v] = find(arr[v]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        arr[x] = y;
        s[y] += s[x];
        r[y] = max(r[y], r[x]);
        l[y] = min(l[y], l[x]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0;  i < n; i++) {
        int a;
        cin >> a;
        bin[i] = a;
        arr[i] = i;
        l[i] = i;
        r[i] = i;
        s[i] = 1;
        m[-a].push_back(i);
    }

    ll res = 0;
    int left = 0, right = 0;

    for (auto& a : m) {
        ll c = -a.first;
        vector<int> v = a.second;

        for (auto& b : v) {
            if (b > 0 && bin[b-1] >= bin[b]) union_set(b-1, b);
            if (b < n-1 && bin[b+1] >= bin[b]) union_set(b, b+1);
            if (s[find(b)]*c > res || (s[find(b)]*c == res && l[find(b)] < left)) {
                res = s[find(b)]*c;
                left = l[find(b)];
                right = r[find(b)];
            }
        }
    }

    cout << left+1 << " " << right+1 << " " << res << endl;
    return 0;
}

