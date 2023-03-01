// Undecidable
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
bool f[maxn][maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n;
    cin>>c>>n;
    f[0][0]=true;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=c;j>=0;j--)
            for(int k=c;k>=0;k--){
                if(j>=x) f[j][k]=f[j][k]||f[j-x][k];
                if(k>=x) f[j][k]=f[j][k]||f[j][k-x];
            }
    }
    int x=-1,y=-1;
    for(int j=0;j<=c;j++)
        for(int k=0;k<=c;k++)
            if(f[j][k]){
                if(x==-1) x=j,y=k;
                else if(x+y<j+k) x=j,y=k;
                else if(x+y==j+k&&abs(x-y)>abs(j-k)) x=j,y=k;
            }
    if(x<y) swap(x,y);
    cout<<x<<" "<<y<<endl;
}

