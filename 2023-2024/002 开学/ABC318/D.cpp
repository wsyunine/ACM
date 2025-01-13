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

int st[20],ans=0;

signed main(){

    int n,ans=0;
    cin>>n;
    vector<vector<int> > mapp(n+1,vector<int>(n+1));
    vector<int> dp(90010,0);

    for(int i=1;i<=n;i++){
        st[i]=0;
        for(int j=i+1;j<=n;j++){
            cin>>mapp[i][j];
            mapp[j][i]=mapp[i][j];
        }
    }

    for(int i=0;i<=(1<<n)-1;i++){
        if(i!=0&&dp[i]==0) continue;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(((i&(1<<(j-1)))==0) && ((i&(1<<(k-1)))==0)){
                    dp[i|(1<<(j-1))|(1<<(k-1))]=max(dp[i|(1<<(j-1))|(1<<(k-1))],dp[i]+mapp[j][k]);
                    ans=max(ans,dp[i|(1<<(j-1))|(1<<(k-1))]);
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}