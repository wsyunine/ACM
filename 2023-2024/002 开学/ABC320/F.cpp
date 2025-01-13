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
#define N 310
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,h,x[N],p[N],f[N],ans=0x3f3f3f3f;
int dp[N][N][N];

int main(){

    memset(dp,0x3f3f3f3f,sizeof dp);

    read(n);read(h);
    for(int i=1;i<=n;i++) read(x[i]);

    for(int i=1;i<=n-1;i++) read(p[i]),read(f[i]);

    for(int i=0;i<=h;i++){
        dp[0][h][i]=0;
    }

    // for(int i=1;i<=n;i++){
    //     int dis=x[i]-x[i-1];
    //     for(int j=0;j<=h;j++){
    //         for(int k=0;k<=h;k++){
    //             if(i==n){
    //                 if(j+dis<=h&&k-dis>=0){
    //                     dp[i][j][k]=min(dp[i][j][k],dp[i-1][j+dis][k-dis]);
    //                 }
    //                 continue;
    //             }
    //             if(j+dis<=h&&k-dis>=0){
    //                 dp[i][j][k]=min(dp[i][j][k],dp[i-1][j+dis][k-dis]);
    //             }
    //             if(j-f[i]+dis>=0&&h-f[i]+dis<=h&&k-dis>=0){
    //                 dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-f[i]+dis][k-dis]+p[i]);
    //             }
    //             if(k+f[i]-dis>=0&&k+f[i]-dis<=h&&j+dis<=h){
    //                 dp[i][j][k]=min(dp[i][j][k],dp[i-1][j+dis][k-dis+f[i]]+p[i]);
    //             }
    //             // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    //         }
    //     }
    // }

    for(int i=0;i<=n-1;i++){
        int dis=x[i+1]-x[i];
        for(int j=0;j<=h;j++){
            for(int k=0;k<=h;k++){

                if(i==n-1){
                    if(j-dis>=0&&k+dis<=h){
                        dp[i+1][j-dis][k+dis]=min(dp[i+1][j-dis][k+dis],dp[i][j][k]);
                    }   
                    continue;
                }

                if(j-dis>=0&&k+dis<=h){
                    dp[i+1][j-dis][k+dis]=min(dp[i+1][j-dis][k+dis],dp[i][j][k]);
                }
                if(j-dis+f[i+1]>=0&&k+dis<=h){
                    dp[i+1][min(j-dis+f[i+1],h)][k+dis]=min(dp[i][j][k]+p[i+1],dp[i+1][min(j-dis+f[i+1],h)][k+dis]);
                }
                if(j-dis>=0&&k+dis-f[i]>=0){
                    dp[i+1][j-dis][min(k+dis-f[i],h)]=min(dp[i+1][j-dis][min(k+dis-f[i],h)],dp[i][j][k]+p[i+1]);
                }

                if(k==h-dis){
                    for(int op=h-f[i+1];op<=h;op++){
                        dp[i+1][j-dis][op]=min(dp[i+1][j-dis][op],dp[i][j][k]+p[i+1]);
                    }
                }
            }
        }
    }

    for(int i=1;i<=h;i++) ans=min(ans,dp[n][i][i]);

    if(ans==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}