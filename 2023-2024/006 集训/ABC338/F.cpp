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
#define N 2000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int dp[N][21];
int mapp[21][21];
int ans=0x3f3f3f3f;

int main(){

    memset(mapp,0x3f,sizeof mapp);
    memset(dp,0x3f,sizeof dp);

    read(n);read(m);
    for(int i=1;i<=n;i++) mapp[i][i]=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        read(a),read(b),read(c);
        mapp[a][b]=c;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mapp[i][k]==0x3f3f3f3f||mapp[k][j]==0x3f3f3f3f) continue;
                mapp[i][j]=min(mapp[i][k]+mapp[k][j],mapp[i][j]);
            }
        }
    }

    for(int i=1;i<=n;i++) dp[1<<(i-1)][i]=0;
    for(int i=1;i<(1<<n)-1;i++){
        for(int j=1;j<=n;j++){
            if(!((1<<(j-1))&i)) continue;
            if(dp[i][j]==0x3f3f3f3f) continue;
            for(int k=1;k<=n;k++){
                if((1<<(k-1))&i) continue;
                if(mapp[j][k]==0x3f3f3f3f) continue;
                dp[i|(1<<(k-1))][k]=min(dp[i|(1<<(k-1))][k],dp[i][j]+mapp[j][k]);
            }
        }
    }

    for(int i=1;i<=n;i++) ans=min(ans,dp[(1<<n)-1][i]);


    if(ans==0x3f3f3f3f) cout<<"No"<<endl;
    else cout<<ans<<endl;

    return 0;
}