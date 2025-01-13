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
#define N 5000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const int Mod=1e9+7;
int n,res=0;
int x[N];
int pows[N],inv[N];

int fpow(int a,int b){
    b%=Mod;
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

signed main(){

    read(n);
    pows[0]=1;
    for(int i=1;i<=n;i++) read(x[i]),pows[i]=pows[i-1]*x[i]%Mod;

    int sinv=fpow(pows[n],Mod-2);

    for(int i=n;i>=1;i--){
        inv[i]=sinv*pows[i-1]%Mod;
        sinv=sinv*x[i]%Mod;
    }

    for(int i=1;i<=n;i++) (res+=inv[i]*fpow(998244353,n-i)%Mod)%=Mod;

    cout<<res<<endl;

    return 0;
}