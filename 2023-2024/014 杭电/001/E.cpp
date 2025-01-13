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
const int Mod=998244353;

int n;
int t,sum=0;
int s[N];
int f[10000001],ff[10000001];

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

signed main(){

    f[0]=1;
    for(int i=1;i<=10000000;i++) f[i]=f[i-1]*i%Mod;
    ff[10000000]=fpow(f[10000000],Mod-2);
    for(int i=10000000;i>=1;i--) ff[i-1]=ff[i]*i%Mod;
    read(t);
    while(t--){
        for(int i=1;i<=26;i++) s[i]=0;
        read(n);sum=0;
        char c;
        for(int i=1,k;i<=n;i++) cin>>c,read(k),sum+=k,s[c-'a'+1]=k;

        int m;
        if(sum%2){
            m=(sum-1)/2;
            int op=0;
            for(int i=1;i<=26;i++) op+=(s[i]%2);
            if(op!=1){
                cout<<ff[2]<<endl;
                continue;
            }
            int res=ff[sum];
            for(int i=1;i<=26;i++) (res*=f[s[i]])%=Mod;
            (res*=f[m])%=Mod;
            for(int i=1;i<=26;i++) (res*=ff[s[i]/2])%=Mod;
            cout<<(res+1)*ff[2]%Mod<<endl;
        }else{
            m=sum/2;
            int op=0;
            for(int i=1;i<=26;i++) op+=(s[i]%2);
            if(op){
                cout<<ff[2]<<endl;
                continue;
            }
            int res=ff[sum];
            for(int i=1;i<=26;i++) (res*=f[s[i]])%=Mod;
            (res*=f[m])%=Mod;
            for(int i=1;i<=26;i++) (res*=ff[s[i]/2])%=Mod;
            cout<<(1-res+Mod)*ff[2]%Mod<<endl;
        }

    }
    
    return 0;
}