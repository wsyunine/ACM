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
#define N 200010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const int Mod=1e9+7;

int n;
int a[N];
ll p[N];
ll dp[2][4];
int b[N];
ll ans=0;

ll fpow(ll a,ll b){
    ll res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

int main(){

    int t;
    read(t);

    while(t--){
        read(n);ans=0;
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(p[i]);
        for(int i=1;i<=n;i++){
            p[i]=p[i]*fpow(10000,Mod-2)%Mod;
        }

        for(int op1=0;op1<=9;op1++){
            for(int op2=0;op2<=9;op2++){
                for(int j=1;j<=n;j++){
                    b[j]=(((a[j]>>op1)&1)<<1)|((a[j]>>op2)&1);
                    // cout<<b[j]<<" ";
                }
                // cout<<endl;
                dp[1][0]=(1-p[1]+Mod)%Mod;
                dp[1][1]=dp[1][2]=dp[1][3]=0;
                dp[1][b[1]]+=p[1];
                for(int i=2;i<=n;i++){
                    for(int j=0;j<=3;j++){
                        dp[i&1][j]=(dp[i&1^1][j]*(1ll-p[i]+Mod)%Mod+p[i]*dp[i&1^1][j^b[i]]%Mod)%Mod;
                    }
                }
                (ans+=dp[n&1][3]*(1<<(op1+op2))%Mod)%=Mod;
                //cout<<ans<<endl;
            }
        }

        cout<<ans<<endl;
    }
    
    return 0;
}