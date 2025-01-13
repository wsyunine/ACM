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
const int Mod=998244353;

int n;
int m;

int main(){

    read(n),read(m);
    vector<ll> dp(m+1);
    dp[0]=1;
    for(int i=0;i<m;i++){
        vector<ll> ndp(m+1);
        for(int j=i;j>=0;j--){
            (ndp[j+1]+=dp[j])%=Mod;
            if(j) (ndp[j-1]+=dp[j])%=Mod;
        }
        swap(dp,ndp);
        //cout<<endl;
    }

    vector<ll> f(m+1);
    f[0]=1;
    for(int i=0;i<n-1;i++){
        vector<ll> nf(m+1);
        for(int j=0;j<=m;j++){
            for(int k=0;k+j<=m;k++){
                (nf[k+j]+=f[j]*dp[k]%Mod)%=Mod;
            }
        }
        swap(nf,f);
    }

    ll res=0;
    for(int i=0;i<=m;i++){
        (res+=f[i]*dp[i]%Mod)%=Mod;
    }
    cout<<res<<endl;

    return 0;
}