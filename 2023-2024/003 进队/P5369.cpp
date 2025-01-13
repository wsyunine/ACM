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

int n;
long long ans=0;
long long Mod=998244353;
int a[22];
long long sum[4000010],f[4000010][2],g[4000010];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int S=0;S<=(1<<n)-1;S++){
        for(int i=1;i<=n;i++){
            if((S>>(i-1))&1) continue;
            sum[S|(1<<(i-1))]=sum[S]+a[i];
        }
    }

    g[0]=1;
    for(int S=0;S<=(1<<n)-1;S++){
        for(int i=1;i<=n;i++){
            if((S>>(i-1))&1) continue;
            if(sum[S|(1<<(i-1))]>=0) continue;
            (g[S|(1<<(i-1))]+=g[S])%=Mod; 
        }
    }

    f[0][0]=1;
    for(int S=0;S<=(1<<n)-1;S++){
        for(int i=1;i<=n;i++){
            if((S>>(i-1))&1) continue;
            if(sum[S|(1<<(i-1))]<0) (f[S|(1<<(i-1))][1]+=f[S][0])%=Mod;
            else (f[S|(1<<(i-1))][0]+=f[S][0])%=Mod;
        }
    }

    for(int S=0;S<=(1<<n)-1;S++){
        (ans+=(((((f[S][1]+f[S][0])%Mod)*g[(1<<n)-1-S])%Mod)*(sum[S]%Mod+Mod)%Mod)%Mod)%=Mod;
    }

    cout<<ans<<endl;

    return 0;
}