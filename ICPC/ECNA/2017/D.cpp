#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
int n, k;
stack<int> s;
 
int main() {
    cin >> n >> k;
    int res = 0;
 
    for (int i = 0; i < k; i++) {
        string str;
        cin >> str;
        
        if (str == "undo") {
            int a;
            cin >> a;
            for (int i = 0; i < a; i++) {
                int t = s.top();
                s.pop();
                res -= t;
            }
        } else {
            int a = atoi(str.c_str());
            res += a;
            s.push(a);
        }
    }
 
    cout << (res%n+n)%n << "\n"; 
    return 0;
}
