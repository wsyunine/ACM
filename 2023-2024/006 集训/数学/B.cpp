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

int fpow(int a,int b,int p){
    int res=1;b%=p;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res;
}

int n,p;

signed main(){

    read(n),read(p);

    for(int i=1;i<=n;i++){
        printf("%lld\n",fpow(i,p-2,p));
    }

    return 0;
}