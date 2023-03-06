#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int ans=0;
pair<int,int> Q[11];
bool row[10][10],col[10][10];
void dfs_plus(int cur,int target){
    if(cur==m+1){
        if(target==0) ans++;
        return;
    }
    vector<int> nums;
    auto [x,y]=Q[cur];
    for(int i=n;i>=1;i--)
        if(!row[x][i]&&!col[y][i])
            nums.push_back(i);
    for(auto i:nums){
        row[x][i]=col[y][i]=true;
        dfs_plus(cur+1,target-i);
        row[x][i]=col[y][i]=false;
    }
}
void dfs_multi(int cur,int target){
    if(cur==m+1){
        if(target==1) ans++;
        return;
    }
    vector<int> nums;
    auto [x,y]=Q[cur];
    for(int i=n;i>=1;i--)
        if(!row[x][i]&&!col[y][i])
            nums.push_back(i);
    for(auto i:nums){
        row[x][i]=col[y][i]=true;
        if(target%i==0) dfs_multi(cur+1,target/i);
        row[x][i]=col[y][i]=false;
    }
}
int main(){
    char tmp,op;
    scanf("%d%d%d%c%c",&n,&m,&t,&tmp,&op);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Q[i]=make_pair(x,y);
    }
    if(op=='-'){
        // ensure m == 2
        if(t>n-1) ans=0;
        else ans=2*(n-t);
    }
    else if(op=='/'){
        // ensure m == 2
        if(t==1) ans=0;
        else{
            int cnt=1;
            while(cnt*t<=n) cnt++;
            cnt--;
            ans=2*cnt;
        }
    }
    else{
        if(op=='+') dfs_plus(1,t);
        else dfs_multi(1,t);
    }
    printf("%d\n",ans);
}
/*
8 3 6 *
5 2 6 2 5 1
 
*/
