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
int mapp[40][40];
int vis[40][40];
int idx=0;

void dfs(int x,int y){
    // cout<<idx<<endl; 
    vis[x][y]=1;
    if(x==1||y==1||x==n||y==n) idx=1;
    
    if(x!=1&&mapp[x-1][y]==0&&!vis[x-1][y]) dfs(x-1,y);
    if(y!=1&&mapp[x][y-1]==0&&!vis[x][y-1]) dfs(x,y-1);
    if(x!=n&&mapp[x+1][y]==0&&!vis[x+1][y]) dfs(x+1,y);
    if(y!=n&&mapp[x][y+1]==0&&!vis[x][y+1]) dfs(x,y+1);
}

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            read(mapp[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mapp[i][j]!=0||vis[i][j]) continue;
            idx=0;
            cout<<i<<" "<<j<<"!"<<endl;
            dfs(i,j);
            if(!idx) mapp[i][j]=2;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<mapp[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

