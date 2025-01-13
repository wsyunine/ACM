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

map<int,int> dp[1010];
int n,m;
int a[N],dx;

signed main(){

    read(n),read(m);
    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=0;i<=m;i++){
        for(int j=-6;j<=n;j++) dp[i][j]=0x3f3f3f3f;
    }
    for(int i=0;i<=m;i++) dp[i][0]=0;

    for(int i=1;i<=m;i++){
        for(int j=-6;j<=n;j++) dp[i][j]=dp[i-1][j];
        for(int j=-6;j<=n;j++){
            if(j-a[i]>=-6) dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]]+1);
            if(n-j<=a[i]-1&&n-j>0) dp[i][j]=min(dp[i][j],dp[i-1][n-(a[i]-(n-j))]+1);
        }
    }

    if(dp[m][n]>=0x3f3f3f3f) cout<<-1<<endl;
    else cout<<dp[m][n]<<endl;

    return 0;
}