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
using namespace std;
#define N 100010 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int d[101][101],st[101];
int n,ans=0;

void dfs(int x,int dis){
    ans=max(ans,dis);
    for(int i=1;i<=n;i++){
        if(st[i]||d[x][i]==1e9||i==x) continue;
        st[i]=1;
        dfs(i,dis+d[x][i]);
        st[i]=0;
    }
}

int main(){

    int m;
    cin>>n>>m;
    int a,b,c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=1e9;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        d[a][b]=c;
        d[b][a]=c;
    }

    for(int i=1;i<=n;i++){
        st[i]=1;
        dfs(i,0);
        st[i]=0;
    }

    cout<<ans<<endl;
    
    return 0;
}