#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T,q=1;
int n,m;
int a[710][710];
int mapp[N];
int vis[710][710];

int dfs(int x,int y,int id){
    int res=1;
    vis[x][y]=1;
    if(x>1&&!vis[x-1][y]&&a[x-1][y]==id) res+=dfs(x-1,y,id);
    if(x<n&&!vis[x+1][y]&&a[x+1][y]==id) res+=dfs(x+1,y,id);
    if(y>1&&!vis[x][y-1]&&a[x][y-1]==id) res+=dfs(x,y-1,id);
    if(y<m&&!vis[x][y+1]&&a[x][y+1]==id) res+=dfs(x,y+1,id);
    return res;
}

void solve() {
    read(n),read(m);
    for(int i=1;i<=n*m;i++) mapp[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(a[i][j]);
            vis[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                mapp[a[i][j]]=max(dfs(i,j,a[i][j]),mapp[a[i][j]]);
            }
        }
    }

    int res=0,mxd=0;
    for(int i=1;i<=n*m;i++){
        mapp[i]=min(mapp[i],2);
        res+=mapp[i];
        mxd=max(mxd,mapp[i]);
    }
    cout<<res-mxd<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}