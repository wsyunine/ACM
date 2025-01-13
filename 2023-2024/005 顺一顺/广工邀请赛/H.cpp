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

int n;
int a[N],b[N],c[N];
int g,ans1=0,ans2=1e18;

int gcd(int a,int b){
    if(b>a) swap(a,b);
    return b==0?a:gcd(b,a%b);
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<n;i++) a[i]=a[i]-a[i+1];
    g=a[1];
    for(int i=2;i<n;i++) g=gcd(g,a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    for(int i=1;i<=n;i++) read(c[i]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int op=gcd(g,a[n]+b[i]+c[j]);
            ans1=max(ans1,op);
            ans2=min(ans2,op);
        }
    }

    cout<<ans2<<" "<<ans1<<endl;

    return 0;
}