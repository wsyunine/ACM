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
#define int long long
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const int Mod=1e9+7;
int n,m;
int ans=1;

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res%Mod;
}

signed main(){

    read(n),read(m);

    for(int i=1;i<=m;i++) (ans*=i)%=Mod;
    ans=fpow(ans,Mod-2);
    (ans*=fpow(n,m))%=Mod;
    for(int i=n-m;i<=n-1;i++) (ans*=i)%=Mod;

    cout<<ans<<endl;

    return 0;
}