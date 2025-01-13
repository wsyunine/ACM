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
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;

int mindiv[N],pri[N],sum[N],cnt=0;
void primes(int n){
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=i,sum[i]=1,mindiv[i]=i;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
            sum[pri[j]*i]=sum[i]+(i%pri[j]!=0);
        }
    }
}

int main(){

    primes(1000010);

    read(t);
    while(t--){
        int l,r,mn=0x3f3f3f3f;
        long long ans=0;
        read(l);read(r);
        for(int i=l;i<=r;i++){
            ans+=sum[i];
            mn=min(mn,sum[i]);
        }
        printf("%lld\n",ans-mn);
    }

    return 0;
}