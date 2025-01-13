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
#define N 600010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,ans=0;
int a[N],s[N],sum[N];

int main(){

    read(n),read(m);
    for(int i=1;i<=100;i++) sum[i]=0;
    sum[0]++;
    for(int i=1;i<=n;i++) read(a[i]),s[i]=(s[i-1]+a[i])%m,sum[s[i]]++;

    for(int i=0;i<=100;i++){
        if(!sum[i]) continue;
        ans+=(sum[i]*(sum[i]-1)/2);
    }

    cout<<ans<<endl;

    return 0;
}