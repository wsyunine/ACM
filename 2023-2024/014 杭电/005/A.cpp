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
#define N 2000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const int Mod=998244353;

int t;
int n,k;
int inv[N],cc[N],poww[N];

int fmul(int a,int b){
    int res=0;
    for(;b;b>>=1,a=(a+a)%Mod) if(b&1) res=(res+a)%Mod;
    return res;
}

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

void init(){
    poww[0]=(fpow(2,k)-n+Mod)%Mod;cc[0]=1;
    for(int i=1;i<=n;i++) poww[i]=(poww[i-1]+1)%Mod,cout<<poww[i]<<endl,cc[i]=fmul(fmul(cc[i-1],(n-i+1)),inv[i]);
    for(int i=1;i<=n;i++) poww[i]=fmul(poww[i],poww[i-1]);
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    inv[0]=inv[1]=1;
    for(int i=2;i<=1000000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;

    read(t);
    while(t--){
        cin>>n>>k;
        for(int i=0;i<=n;i++) poww[i]=0,cc[i]=0;

        init();

        int ans=0;
        int p=fpow(poww[0],Mod-2);
        for(int i=0,j=n;i<=n;i++,j--){
            int op=fmul(fmul(cc[i],poww[j]),p);
            cout<<op<<endl;
            if(i&1){
                ans=((ans-op)%Mod+Mod)%Mod;
            }else{
                ans=(ans+op)%Mod;
            }
        }
        cout<<ans*poww[n-1]%Mod<<endl;
    }
    
    return 0;
}