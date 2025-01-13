#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,m;
string str;
int mapp[1030][1030],vis[1030][1030];

void dfs2(int x,int y){
    vis[x][y]=-1;
    if(mapp[x-1][y]==-1&&vis[x-1][y]!=-1){
        dfs2(x-1,y);
    }
    if(mapp[x+1][y]==-1&&vis[x+1][y]!=-1){
        dfs2(x+1,y);
    }
    if(mapp[x][y+1]==-1&&vis[x][y+1]!=-1){
        dfs2(x,y+1);
    }
    if(mapp[x][y-1]==-1&&vis[x][y-1]!=-1){
        dfs2(x,y-1);
    }
}

int dfs(int x,int y){
    if(x==0||y==0||x==n+1||y==m+1) return 2;
    if(vis[x][y]==1) return -1;
    if(vis[x][y]==2) return 2;
    if(vis[x][y]==-1) return -1;
    vis[x][y]=1;
    int res;
    if(mapp[x][y]==1){
        res=dfs(x-1,y);
    }
    if(mapp[x][y]==2){
        res=dfs(x+1,y);
    }
    if(mapp[x][y]==3){
        res=dfs(x,y-1);
    }
    if(mapp[x][y]==4){
        res=dfs(x,y+1);
    }
    if(mapp[x][y]==-1){
        dfs2(x,y);
        res=-1;
    }

    if(res==2){
        vis[x][y]=2;
    }
    if(res==-1){
        vis[x][y]=-1;
    }
    return res;
}

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        for(int i=0;i<=n+10;i++) for(int j=0;j<=m+10;j++) mapp[i][j]=0,vis[i][j]=0;
        for(int i=1;i<=n;i++) vis[i][0]=vis[i][m+1]=2;
        for(int i=1;i<=m;i++) vis[0][i]=vis[n+1][i]=2;
        for(int i=1;i<=n;i++){
            cin>>str;
            str=' '+str;
            for(int j=1;j<=m;j++){
                if(str[j]=='U') mapp[i][j]=1;
                if(str[j]=='D') mapp[i][j]=2;
                if(str[j]=='L') mapp[i][j]=3;
                if(str[j]=='R') mapp[i][j]=4;
                if(str[j]=='?') mapp[i][j]=-1;
            }
        }

       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mapp[i][j]>0&&vis[i][j]==0){
                    dfs(i,j);
                }
            }
        }

        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //cout<<vis[i][j]<<" ";
                if(!vis[i][j]){
                    if(vis[i-1][j]==2&&vis[i+1][j]==2&&vis[i][j+1]==2&&vis[i][j-1]==2){
                        vis[i][j]=2;
                    }else vis[i][j]=-1;
                }
                sum+=(vis[i][j]==-1);
            }
            //cout<<endl;
        }

        cout<<sum<<endl;

    }

    return 0;
}