#include "bits/stdc++.h"
using namespace std;
 
typedef int64_t ll;
 
int main() {
    std::string s;
    cin >> s;
 
    ll a = 0, b = 0;
 
    ll size = s.length() / 2;
    for (int i = 0; i < size; i++) {
            a += s[i] - 'A';
            b += s[i + size] - 'A';
    }
 
    a %= 26;
    b %= 26;
 
 
    for (int i = 0; i < size; i++) {
        s[i] = ((s[i] - 'A' + a) % 26) + 'A';
        s[i + size] = ((s[i + size] - 'A' + b) % 26) + 'A';
    }        
 
    for (int i = 0; i < size; i++) {
        s[i] = ((s[i] - 'A' + (s[i + size] - 'A')) % 26) + 'A';
    }
 
    cout << s.substr(0, size) << endl;
 
    return 0;
}
