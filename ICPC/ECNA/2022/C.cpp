// Undecidable
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[14];
int getid(char c){
    if(c=='A') return 1;
    else if('2'<=c&&c<='9') return c-'0';
    else if(c=='T') return 10;
    else if(c=='J') return 11;
    else if(c=='Q') return 12;
    else return 13;
}
const int maxn=105;
ll f[maxn][16];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        int id=getid(c);
        cnt[id]++;
        if(id>10) id=10;
        for(int j=0;j<=15;j++){
            f[i][j]=f[i-1][j];
            if(j>=id) f[i][j]+=f[i-1][j-id];
        }
    }
    ll ans1=2*f[n][15],ans2=0,ans3=0;
    for(int i=1;i<=13;i++)
        if(cnt[i]>=2)
            ans2+=cnt[i]*(cnt[i]-1);
    for(int i=1,j;i<=13;i=j+1){
        while(i<=13&&cnt[i]==0) i++;
        if(i>13) break;
        j=i;
        while(j<=13&&cnt[j]>0) j++;
        j--;
        if(j-i+1>=3){
            ll cur=1;
            for(int k=i;k<=j;k++) cur*=cnt[k];
            ans3+=cur*(j-i+1);
        }
    }
    // cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    cout<<ans1+ans2+ans3<<endl;
}

