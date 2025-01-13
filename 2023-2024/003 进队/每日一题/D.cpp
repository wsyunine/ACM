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
#define int long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],s[N],dp[N],ans=0;

signed main(){

    read(n);
    s[0]=0;
    for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];

    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(i-j<=1) continue;
            if((i-j)%2==0) dp[i]=max(dp[i],dp[j]+s[(i-j)/2-1]*2+a[(i-j)/2]);
            else dp[i]=max(dp[i],dp[j]+s[(i-j)/2]*2);
        }
    }

    for(int i=1;i<n;i++){
        if((n+1-i)%2==0) ans=max(ans,dp[i]+s[(n+1-i)/2-1]*2+a[(n+1-i)/2]);
        else ans=max(ans,dp[i]+s[(n+1-i)/2]*2);
    }

    ans=max(ans,dp[n]);

    cout<<ans<<endl;

    return 0;
}