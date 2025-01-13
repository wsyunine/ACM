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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int m;
int mapp[1010][1010];
int dp[1010][1010][5];
int vis[1010][1010];
int q;

//0上1下2左3右

void dfs1(int x,int y,int id,int s){//id是进来的方向
    if(x<1||y<1||x>n||y>m) return;
    dp[x][y][id^1]=s;
    vis[x][y]=1;
    if(mapp[x][y]==1){
        if(id==0){
            if(vis[x+1][y]) dfs1(x+1,y,1,s);
            else dfs1(x+1,y,1,s+1);
        }
        if(id==1){
            if(vis[x-1][y]) dfs1(x-1,y,1,s);
            else dfs1(x-1,y,1,s+1);
        }
        if(id==2){
            dfs1(x,y-1,2,s);
        }
        if(id==3){
            dfs1(x,y+1,3,s);
        }
    }
    if(mapp[x][y]==2){
        if(id==2){
            if(vis[x][y+1]) dfs1(x,y+1,3,s);
            else dfs1(x,y+1,3,s+1);
        }
        if(id==3){
            if(vis[x][y-1]) dfs1(x,y-1,2,s);
            else dfs1(x,y-1,2,s+1);
        }
        if(id==0){
            dfs1(x-1,y,0,s);
        }
        if(id==1){
            dfs1(x+1,y,1,s);
        }
    }
    if(mapp[x][y]==3){
        if(id==0){
            if(vis[x][y+1]) dfs1(x,y+1,3,s);
            else dfs1(x,y+1,3,s+1);
        }
        if(id==1){
            if(vis[x][y-1]) dfs1(x,y-1,2,s);
            else dfs1(x,y-1,2,s+1);
        }
        if(id==2){
            if(vis[x+1][y]) dfs1(x+1,y,1,s);
            else dfs1(x+1,y,1,s+1);
        }
        if(id==3){
            if(vis[x-1][y]) dfs1(x-1,y,0,s);
            else dfs1(x-1,y,0,s+1);
        }
    }
    if(mapp[x][y]==4){
        if(id==0){
            if(vis[x][y-1]) dfs1(x,y-1,2,s);
            else dfs1(x,y-1,2,s+1);
        }
        if(id==1){
            if(vis[x][y+1]) dfs1(x,y+1,3,s);
            else dfs1(x,y+1,3,s+1);
        }
        if(id==2){
            if(vis[x-1][y]) dfs1(x-1,y,0,s);
            else dfs1(x-1,y,0,s+1);
        }
        if(id==3){
            if(vis[x+1][y]) dfs1(x+1,y,1,s);
            else dfs1(x+1,y,1,s+1);
        }
    }
    vis[x][y]=0;
}

int dfs2(int x,int y,int id,int s,int sx,int sy,int sid){
    if(x==sx&&y==sy&&id==sid&&s) return s;
    vis[x][y]=1;
    if(mapp[x][y]==1){
        if(id==0){
            if(vis[x+1][y]) dp[x][y][id^1]=dfs2(x+1,y,1,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x+1,y,1,s+1,sx,sy,sid);
        }
        if(id==1){
            if(vis[x-1][y]) dp[x][y][id^1]=dfs2(x-1,y,1,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x-1,y,1,s+1,sx,sy,sid);
        }
        if(id==2){
            dp[x][y][id^1]=dfs2(x,y-1,2,s,sx,sy,sid);
        }
        if(id==3){
            dp[x][y][id^1]=dfs2(x,y+1,3,s,sx,sy,sid);
        }
    }
    if(mapp[x][y]==2){
        if(id==2){
            if(vis[x][y+1]) dp[x][y][id^1]=dfs2(x,y+1,3,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y+1,3,s+1,sx,sy,sid);
        }
        if(id==3){
            if(vis[x][y-1]) dp[x][y][id^1]=dfs2(x,y-1,2,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y-1,2,s+1,sx,sy,sid);
        }
        if(id==0){
            dp[x][y][id^1]=dfs2(x-1,y,0,s,sx,sy,sid);
        }
        if(id==1){
            dp[x][y][id^1]=dfs2(x+1,y,1,s,sx,sy,sid);
        }
    }
    if(mapp[x][y]==3){
        if(id==0){
            if(vis[x][y+1]) dp[x][y][id^1]=dfs2(x,y+1,3,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y+1,3,s+1,sx,sy,sid);
        }
        if(id==1){
            if(vis[x][y-1]) dp[x][y][id^1]=dfs2(x,y-1,2,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y-1,2,s+1,sx,sy,sid);
        }
        if(id==2){
            if(vis[x+1][y]) dp[x][y][id^1]=dfs2(x+1,y,1,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x+1,y,1,s+1,sx,sy,sid);
        }
        if(id==3){
            if(vis[x-1][y]) dp[x][y][id^1]=dfs2(x-1,y,0,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x-1,y,0,s+1,sx,sy,sid);
        }
    }
    if(mapp[x][y]==4){
        if(id==0){
            if(vis[x][y-1]) dp[x][y][id^1]=dfs2(x,y-1,2,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y-1,2,s+1,sx,sy,sid);
        }
        if(id==1){
            if(vis[x][y+1]) dp[x][y][id^1]=dfs2(x,y+1,3,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x,y+1,3,s+1,sx,sy,sid);
        }
        if(id==2){
            if(vis[x-1][y]) dp[x][y][id^1]=dfs2(x-1,y,0,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x-1,y,0,s+1,sx,sy,sid);
        }
        if(id==3){
            if(vis[x+1][y]) dp[x][y][id^1]=dfs2(x+1,y,1,s,sx,sy,sid);
            else dp[x][y][id^1]=dfs2(x+1,y,1,s+1,sx,sy,sid);
        }
    }
    vis[x][y]=0;
    return dp[x][y][id^1];
}

int main(){

    read(n),read(m);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char op;
            cin>>op;
            if(op=='-') mapp[i][j]=1;
            if(op=='|') mapp[i][j]=2;
            if(op=='/') mapp[i][j]=3;
            if(op=='\\') mapp[i][j]=4;
        }
    }

    for(int i=1;i<=m;i++){
        dfs1(1,i,1,0);
        dfs1(n,i,0,0);
    }
    for(int i=1;i<=n;i++){
        dfs1(i,1,3,0);
        dfs1(i,m,2,0);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=3;k++){
                if(~dp[i][j][k]){
                    if(k==0){
                        dp[i][j][k]=dfs2(i-1,j,0,0,i-1,j,0);
                    }
                    if(k==1){
                        dp[i][j][k]=dfs2(i+1,j,1,0,i+1,j,1);
                    }
                    if(k==2){
                        dp[i][j][k]=dfs2(i,j-1,2,0,i,j-1,2);
                    }
                    if(k==3){
                        dp[i][j][k]=dfs2(i,j+1,3,0,i,j+1,3);
                    }
                }
            }
        }
    }

    for(int k=0;k<=3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    read(q);
    while(q--){
        int x,y;
        string s;
        read(x),read(y);
        cin>>s;
        if(s[0]=='a') cout<<dp[x][y][0]<<endl;
        if(s[0]=='b') cout<<dp[x][y][1]<<endl;
        if(s[0]=='l') cout<<dp[x][y][2]<<endl;
        if(s[0]=='r') cout<<dp[x][y][3]<<endl;
    }

    return 0;
}