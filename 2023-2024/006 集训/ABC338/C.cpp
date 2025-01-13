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

int n;
int q[N];
int a[N];
int b[N];

int maxa,ans=0;

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(q[i]);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);

    maxa=0x3f3f3f3f;
    for(int i=1;i<=n;i++) if(a[i]) maxa=min(maxa,q[i]/a[i]);
    
    for(int i=0;i<=maxa;i++){
        int idx=0x3f3f3f3f;
        for(int j=1;j<=n;j++) if(b[j]) idx=min(idx,(q[j]-i*a[j])/b[j]);
        ans=max(ans,i+idx);
    }

    cout<<ans<<endl;

    return 0;
}