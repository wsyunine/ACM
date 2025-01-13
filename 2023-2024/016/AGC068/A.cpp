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
int l;
int ans=0;
int c[N];

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

int C(int a,int b){
    int res=1,op=1;
    for(int i=a;i>a-b;i--){
        (res*=i)%=Mod;
    }
    for(int i=1;i<=b;i++){
        (op*=i)%=Mod;
    }
    op=fpow(op,Mod-2);
    return op*res%Mod;
}

signed main(){

    read(l),read(n);

    if(n>l/2){
        cout<<C(l,n)*(l/2)%Mod<<endl;
        return 0;
    }

    c[n-2]=1;
    for(int i=n-1;i<=l;i++){
        c[i]=c[i-1]*fpow(i-(n-2),Mod-2)%Mod*i%Mod;
        // cout<<c[i]<<" ";
    }

    for(int i=1;i<=l/2;i++){
        if(i==l/2){
            if(l%2){
                (ans+=2*c[l-2]%Mod*i%Mod)%=Mod;
            }else{
                (ans+=c[l-2]%Mod*i%Mod)%=Mod;
            }
            break;
        }
        (ans+=2*c[i-1]%Mod*i%Mod)%=Mod;
        cout<<2*c[i-1]%Mod*i%Mod<<endl;
    }

    ans=ans*l%Mod*fpow(n,Mod-2)%Mod;

    cout<<ans<<endl;

    return 0;
}