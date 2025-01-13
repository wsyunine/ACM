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
#define N 500010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll INF=1e18;

int t;
int n;
ll a[N],b[N],c[N];
ll dp[N][5];

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),dp[i][1]=dp[i][0]=dp[i][3]=dp[i][2]=dp[i][4]=INF;
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++) read(c[i]);
        
        dp[1][0]=0,dp[1][1]=b[1],dp[1][2]=b[1]*2ll;
        if(a[1]>1) dp[1][3]=c[1];
        if(a[1]>2) dp[1][4]=c[1]*2ll;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]) dp[i][0]=min(dp[i][0],dp[i-1][0]);
            if(a[i]!=a[i-1]+1) dp[i][0]=min(dp[i][0],dp[i-1][1]);
            if(a[i]!=a[i-1]+2) dp[i][0]=min(dp[i][0],dp[i-1][2]);
            if(a[i]!=a[i-1]-1) dp[i][0]=min(dp[i][0],dp[i-1][3]);
            if(a[i]!=a[i-1]-2) dp[i][0]=min(dp[i][0],dp[i-1][4]);
            if(a[i]+1!=a[i-1]) dp[i][1]=min(dp[i][1],dp[i-1][0]+b[i]);
            if(a[i]+1!=a[i-1]+1) dp[i][1]=min(dp[i][1],dp[i-1][1]+b[i]);
            if(a[i]+1!=a[i-1]+2) dp[i][1]=min(dp[i][1],dp[i-1][2]+b[i]);
            if(a[i]+1!=a[i-1]-1) dp[i][1]=min(dp[i][1],dp[i-1][3]+b[i]);
            if(a[i]+1!=a[i-1]-2) dp[i][1]=min(dp[i][1],dp[i-1][4]+b[i]);
            if(a[i]+2!=a[i-1]) dp[i][2]=min(dp[i][2],dp[i-1][0]+b[i]*2ll);
            if(a[i]+2!=a[i-1]+1) dp[i][2]=min(dp[i][2],dp[i-1][1]+b[i]*2ll);
            if(a[i]+2!=a[i-1]+2) dp[i][2]=min(dp[i][2],dp[i-1][2]+b[i]*2ll);
            if(a[i]+2!=a[i-1]-1) dp[i][2]=min(dp[i][2],dp[i-1][3]+b[i]*2ll);
            if(a[i]+2!=a[i-1]-2) dp[i][2]=min(dp[i][2],dp[i-1][4]+b[i]*2ll);
            if((a[i]-1!=a[i-1])&&(a[i]>1)) dp[i][3]=min(dp[i][3],dp[i-1][0]+c[i]);
            if((a[i]-1!=a[i-1]+1)&&(a[i]>1)) dp[i][3]=min(dp[i][3],dp[i-1][1]+c[i]);
            if((a[i]-1!=a[i-1]+2)&&(a[i]>1)) dp[i][3]=min(dp[i][3],dp[i-1][2]+c[i]);
            if((a[i]-1!=a[i-1]-1)&&(a[i]>1)) dp[i][3]=min(dp[i][3],dp[i-1][3]+c[i]);
            if((a[i]-1!=a[i-1]-2)&&(a[i]>1)) dp[i][3]=min(dp[i][3],dp[i-1][4]+c[i]);
            if((a[i]-2!=a[i-1])&&(a[i]>2)) dp[i][4]=min(dp[i][4],dp[i-1][0]+c[i]*2ll);
            if((a[i]-2!=a[i-1]+1)&&(a[i]>2)) dp[i][4]=min(dp[i][4],dp[i-1][1]+c[i]*2ll);
            if((a[i]-2!=a[i-1]+2)&&(a[i]>2)) dp[i][4]=min(dp[i][4],dp[i-1][2]+c[i]*2ll);
            if((a[i]-2!=a[i-1]-1)&&(a[i]>2)) dp[i][4]=min(dp[i][4],dp[i-1][3]+c[i]*2ll);
            if((a[i]-2!=a[i-1]-2)&&(a[i]>2)) dp[i][4]=min(dp[i][4],dp[i-1][4]+c[i]*2ll);
        }
        
        cout<<min(dp[n][0],min(dp[n][1],min(dp[n][2],min(dp[n][3],dp[n][4]))))<<endl;
    }

    

    return 0;
}