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

int n,k;
ll s[17];
ll ans=0;
ll dp[100010][17];

int main(){

    read(n);read(k);
    for(int i=1,j=1;i<=n;i++,j=j*2) read(s[i]),dp[j][i]=1;

    for(int S=1;S<=(1<<n)-1;S++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((S>>(j-1))&1) continue;
                if(abs(s[i]-s[j])>k) dp[S|(1<<(j-1))][j]+=dp[S][i];
            }
        }
    }

    for(int i=1;i<=n;i++) ans+=dp[(1<<n)-1][i];

    cout<<ans<<endl;

    return 0;
}