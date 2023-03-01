// Undecidable
#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;
int pre[4][maxn];
int getid(char c){
    if(c=='A') return 0;
    else if(c=='T') return 1;
    else if(c=='G') return 2;
    else return 3;
}
char chs[4]={'A','T','G','C'};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        pre[getid(s[i])][i]=1;
        for(int j=0;j<4;j++) pre[j][i]+=pre[j][i-1];
    }
    int m;
    cin>>m;
    while(m--){
        vector<pair<int,int>> cur;
        int l,r;
        cin>>l>>r;

        l--;r--;
        for(int j=0;j<4;j++)
            cur.push_back(make_pair(pre[j][r]-pre[j][l-1],4-j));
        sort(cur.begin(),cur.end());
        reverse(cur.begin(),cur.end());
        for(auto [_,c]:cur) cout<<chs[4-c];
        cout<<endl;
    }
}
