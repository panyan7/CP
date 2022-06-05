#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
 
int n, m;
bool isa[500][500], hasa[500][500];
vector<int> graphIs[500], graphHas[500];
map<string, int> con;
 
int main() {
    cin >> n >> m;
    memset(isa, false, sizeof(isa));
    memset(hasa, false, sizeof(hasa));
 
    int index = 0;
    for (int i = 0; i < n; i++) {
        string a, s, b;
        cin >> a >> s >> b;
        if (con.count(a) == 0) con[a] = index++;
        if (con.count(b) == 0) con[b] = index++;
 
        if (s == "is-a") graphIs[con[a]].push_back(con[b]);
        else graphHas[con[a]].push_back(con[b]);
    }
 
    for (int i = 0; i < index; i++) {
        stack<int> st;
        st.push(i);
 
        while (!st.empty()) {
            int p = st.top();
            st.pop();
 
            isa[i][p] = true;
            for (auto& a : graphIs[p]) {
                if (!isa[i][a]) st.push(a);
                isa[i][a] = true;
            }
        }
    }
 
    for (int i = 0; i < index; i++) {
        stack<int> st;
        for (int j = 0; j < index; j++) {
            if (!isa[i][j]) continue;
            for (auto& a : graphHas[j]) {
                if (!hasa[i][a]) st.push(a);
                hasa[i][a] = true;
            }
        }
 
        while (!st.empty()) {
            int p = st.top();
            st.pop();
 
            for (auto& a : graphIs[p]) {
                if (!hasa[i][a]) st.push(a);
                hasa[i][a] = true;
            }
 
            for (auto& a : graphHas[p]) {
                if (!hasa[i][a]) st.push(a);
                hasa[i][a] = true;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        string a, s, b;
        cin >> a >> s >> b;
 
        if (s == "is-a") cout << "Query " << i+1 << ": " << (isa[con[a]][con[b]]?"true":"false") << "\n";
        else cout << "Query " << i+1 << ": " << (hasa[con[a]][con[b]]?"true":"false") << "\n";
    }
    
    return 0;
}
