#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>

int tt = 1, n, m, k;
int two[26][26], three[26][26][26];

unordered_set<string> st;

// check long long
void solve() {
    memset(two, 0, sizeof(two));
    memset(three, 0, sizeof(three));
    cin >> n;
    vector<string> s(n);
    st.clear();
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == s[i].back()) {
            ok = true;
            break;
        }
        if (s[i].size() == 3) {
            if (three[s[i][2]-'a'][s[i][1]-'a'][s[i][0]-'a'])
                ok = true;
            if (two[s[i][2]-'a'][s[i][1]-'a'])
                ok = true;
            three[s[i][0]-'a'][s[i][1]-'a'][s[i][2]-'a']++;
        } else {
            if (two[s[i][1]-'a'][s[i][0]-'a'])
                ok = true;
            for (int j = 0; j < 26; j++)
                if (three[s[i][1]-'a'][s[i][0]-'a'][j])
                    ok = true;
            two[s[i][0]-'a'][s[i][1]-'a']++;
        }
        if (ok)
            break;
    }
    cout << (ok ? "YES\n" : "NO\n");
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
