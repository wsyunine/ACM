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

const int Mod=1e9+7;
int n,s;
int f[N],invn,ans=0;

int fpow(int a,int b){
    a%=Mod;int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

int C(int n,int m){
    if(n<0||m<0||n<m) return 0;
    if(m==0||n%Mod==0) return 1;
    int res=1;
    for(int i=n-m+1;i<=n;i++) (res*=(i%Mod))%=Mod;
    res=res*invn%Mod;
    return res; 
}

signed main(){

    read(n);read(s);
    for(int i=1;i<=n;i++) read(f[i]);

    invn=1;
    for(int i=1;i<n;i++) invn=invn*i%Mod;
    invn=fpow(invn,Mod-2);

    for(int i=0;i<=(1<<n)-1;i++){
        int sop=0,cn=s+n-1,cm=n-1;
        for(int j=1,k=1;j<=n;j++,k<<=1){
            if(i&k) sop++,cn-=(f[j]+1);
        }
        // cout<<i<<" "<<sop<<" "<<cn<<" "<<cm<<endl;
        if(sop&1) (ans-=C(cn,cm))%=Mod;
        else (ans+=C(cn,cm))%=Mod;
    }

    cout<<(ans+Mod)%Mod<<endl;

    return 0;
}