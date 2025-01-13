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

int t;
int n,m;
int mapp[3010][3010],u[3010][3010],vis[3010];
int ide=1;

void dfs(int x,int id,int fa){
    vis[x]=id;
    // cout<<x<<" "<<id<<endl;
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        if(i==fa) continue;
        if(u[x][i]){
            // cout<<x<<" "<<i<<endl;
            if(vis[i]==id){ide=0;return;}
            if(!vis[i]) dfs(i,id^1,x);
        }
    }
}

int main(){

    read(t);
    while(t--){
        ide=1;
        read(n),read(m);
        if(n>=3000){
            for(int i=1,j,k;i<=m;i++) read(j),read(k);
            cout<<"No"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mapp[i][j]=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1,j,k;i<=m;i++){
            read(j),read(k);
            mapp[j][k]=mapp[k][j]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(!mapp[i][j]) u[i][j]=u[j][i]=1;
                else u[i][j]=u[j][i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs(i,2,0);
            if(!ide) break;
        }
        // for(int i=1;i<=n;i++) cout<<vis[i]<<endl;
        if(ide) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}