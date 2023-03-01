// Undecidable
#include <bits/stdc++.h>
using namespace std;
const int maxn=52;
int DIFF=0,E=0,C,R;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool g[maxn][maxn][4];
int getid(char c){
    if(c=='N') return 0;
    else if(c=='E') return 1;
    else if(c=='S') return 2;
    else return 3;
}
int dis[maxn][maxn];
pair<int,int> update_pos(pair<int,int> pos, int d){
    auto [x,y]=pos;
    if(!g[x][y][d]) return pos;
    int nx=x+dir[d][0],ny=y+dir[d][1];
    if(nx==0&&ny==E) return make_pair(nx,ny);
    if(nx<1||nx>R||ny<1||ny>C) return pos;
    return make_pair(nx,ny);
}
void get_dis(){
    queue<pair<int,int>> Q;
    Q.push(make_pair(1,E));
    memset(dis,0x37,sizeof(dis));
    dis[1][E]=0;
    while(!Q.empty()){
        auto pos=Q.front();Q.pop();
        for(int i=0;i<4;i++){
            auto npos=update_pos(pos,i);
            if(npos==pos) continue;
            if(dis[npos.first][npos.second]>dis[pos.first][pos.second]+1){
                dis[npos.first][npos.second]=dis[pos.first][pos.second]+1;
                Q.push(npos);
            }
        }
    }
}
pair<int,int> f[maxn][maxn][maxn][maxn];
bool vis[maxn][maxn][maxn][maxn];
pair<int,int> ans=make_pair(maxn*maxn*maxn,0);
void get_ans(int sr1,int sc1,int sr2,int sc2){
    auto epos=make_pair(0,E);
    memset(vis,0,sizeof(vis));
    f[sr1][sc1][sr2][sc2]=make_pair(0,0);
    queue<pair<pair<int,int>,pair<int,int>>> Q;
    Q.push(make_pair(make_pair(sr1,sc1),make_pair(sr2,sc2)));
    while(!Q.empty()){
        auto [pos1,pos2]=Q.front();Q.pop();
        auto [r1,c1]=pos1;auto [r2,c2]=pos2;
        auto [cur_step,cur_bump]=f[r1][c1][r2][c2];
        if(vis[r1][c1][r2][c2]) continue;
        vis[r1][c1][r2][c2]=true;
        // printf("(%d,%d)&(%d,%d): step %d, bump %d\n",r1,c1,r2,c2,cur_step,cur_bump);
        for(int i=0;i<4;i++){
            auto npos1=update_pos(pos1,i),npos2=update_pos(pos2,(i+DIFF)%4);
            int nbump=(npos1==pos1)+(npos2==pos2);
            if(nbump>=2||npos1==npos2) continue;
            auto nf=make_pair(cur_step+1,cur_bump+nbump);
            if(nf<f[npos1.first][npos1.second][npos2.first][npos2.second]){
                f[npos1.first][npos1.second][npos2.first][npos2.second]=nf;
                if(npos1==epos){
                    // printf("step %d, bump %d\n",nf.first,nf.second);
                    auto ansf=make_pair(nf.first+dis[npos2.first][npos2.second],nf.second);
                    // printf("step %d, bump %d\n",ansf.first,ansf.second);
                    ans=min(ans,ansf);
                }
                else if(npos2==epos){
                    auto ansf=make_pair(nf.first+dis[npos1.first][npos1.second],nf.second);
                    ans=min(ans,ansf);
                }
                else Q.push(make_pair(npos1,npos2));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++){
            for(int k=0;k<4;k++)
                g[i][j][k]=true;
            for(int k=0;k<maxn;k++)
                for(int l=0;l<maxn;l++)
                    f[i][j][k][l]=make_pair(maxn*maxn*maxn,0);
        }
    cin>>C>>R>>E;
    int c1,r1,c2,r2;char d1,d2;
    cin>>c1>>r1>>d1>>c2>>r2>>d2;
    DIFF=(getid(d2)-getid(d1)+4)%4;

    int n;
    cin>>n;
    while(n--){
        int c,r;
        cin>>c>>r;
        g[r][c][0]=g[r+1][c][2]=false;
    }
    cin>>n;
    while(n--){
        int c,r;
        cin>>c>>r;
        g[r][c][1]=g[r][c+1][3]=false;
    }
    get_dis();
    get_ans(r1,c1,r2,c2);
    cout<<ans.first+1<<" "<<ans.second<<endl;
}

