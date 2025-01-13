#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
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
#define N 500010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k;
int t;
int a[N],pre[N],suf[N];

signed main(){

    read(t);
    while(t--){
        read(n),read(k);
        pre[0]=0,suf[n+1]=0;
        for(int i=1;i<=n;i++) read(a[i]),pre[i]=pre[i-1]+a[i];
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
        reverse(suf+1,suf+1+n);

        if(k>=pre[n]){cout<<n<<endl;continue;}

        int ans1=upper_bound(pre+1,pre+1+n,k-k/2)-pre-1;
        int ans2=upper_bound(suf+1,suf+1+n,k/2)-suf-1;

        if(ans1+ans2>n) cout<<n<<endl;
        else cout<<ans1+ans2<<endl;
    }

    return 0;
}