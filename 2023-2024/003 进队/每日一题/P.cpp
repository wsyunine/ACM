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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int a[N],c[N],vis[N];
ll dp[5010][5010];
int mapp[5010][5010];
ll ans=0x3f3f3f3f3f3f3f;

int main(){

    read(n),read(m);

    memset(dp,0x3f3f3f3f,sizeof dp);

    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(c[i]),vis[i]=0;
    for(int i=1,j;i<=m;i++) read(j),vis[j]=1;

    for(int i=1;i<=n;i++){
        int op=0x3f3f3f3f;
        for(int j=i;j<=n;j++){
            op=min(op,c[j]);
            mapp[i][j]=op;
        }
    }

    for(int i=0;i<=n;i++) dp[i][0]=0;
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<cnt;j++) dp[i][j]=dp[i-1][j];
        for(int j=cnt;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+mapp[i-j+1][i]+a[i];
            if(!vis[i]) dp[i][j]=min(dp[i-1][j],dp[i][j]);
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
        if(vis[i]) cnt++;
    }

    for(int i=m;i<=n;i++) ans=min(ans,dp[n][i]);

    cout<<ans<<endl;

    return 0;
}