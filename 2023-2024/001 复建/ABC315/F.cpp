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

int main(){

    int n;
    cin>>n;
    vector<int> x(n+1),y(n+1);
    vector<vector<double> > dp(n+1,vector<double>(31,1e9));

    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    dp[1][0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<=min(i-1,30);j++){
            for(int k=i+1;k<=n&&j+k-i-1<=30;k++){
                int p=j+k-i-1;
                dp[k][p]=min(dp[k][p],dp[i][j]+sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])));
            }
        }
    }

    double ans=1e9;
    for(int i=0;i<=30;i++){
        ans=min(ans,dp[n][i]+(i==0?0:1<<(i-1)));
    }

    cout<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}