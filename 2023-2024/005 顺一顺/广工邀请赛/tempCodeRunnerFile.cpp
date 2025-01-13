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

int dp[1010][1010];
int n,m;
int a[N],ans=0x3f3f3f3f,dx;

int main(){

    memset(dp,0x3f,sizeof dp);

    read(n),read(m);
    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=0;i<=m;i++) dp[0][i]=0;

    ans=0x3f3f3f3f;

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[i][j-1];
            if(i-a[j]>=0) dp[i][j]=min(dp[i][j-1],dp[i-a[j]][j-1]+1);
            if(n-i<=a[j]-1&&n-i>0&&n-(a[j]-(n-i))>=0) dp[i][j]=min(dp[i][j-1],dp[n-(a[j]-(n-i))][j-1]+1);
        }
    }

    for(int i=1;i<=m;i++) ans=min(ans,dp[n][i]);

    if(ans>=0x3f3f3f3f) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}