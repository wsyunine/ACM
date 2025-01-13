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
int t;
int n,m,ans1=1,ans2=1,ans3=1;

int fpow(int a,int b){
    int res=1%Mod;a%=Mod;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=(res*a)%Mod;
    return res%Mod;
}

signed main(){

    read(t);
    while(t--){
        read(n),read(m);
        ans1=ans2=ans3=1;

        //C_{n-1}^{m-1}*n!

        for(int i=1;i<=n;i++) (ans2*=i)%=Mod;
        for(int i=1;i<=m-1;i++) (ans1*=(n-i))%=Mod;
        for(int i=1;i<=m-1;i++) (ans3*=i)%=Mod;
        cout<<fpow(ans3,Mod-2)*ans1%Mod*ans2%Mod<<endl;
    }

    return 0;
}