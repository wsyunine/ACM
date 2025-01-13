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
#define N 500010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
int m,k,pos=0,l,r,pre=0;
int a[N],d[N],f[N],ans=0;

signed main(){

    read(t);
    while(t--){
        read(n),read(m),read(k);pos=-1;ans=0;pre=0;
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=m;i++) read(d[i]);
        for(int i=1;i<=k;i++) read(f[i]);

        for(int i=2;i<=n;i++){
            if(pos<a[i]-a[i-1]){
                pre=pos;
                pos=a[i]-a[i-1];
                l=a[i-1];
                r=a[i];
                ans=0;
            }else if(pos==a[i]-a[i-1]){
                ans=pos;
            }else if(pre<a[i]-a[i-1]){
                pre=a[i]-a[i-1];
            }
        }
        if(ans){
            cout<<ans<<endl;
            continue;
        }

        sort(d+1,d+1+m);
        sort(f+1,f+1+k);

        ans=pos;

        for(int i=1;i<=m;i++){
            if(d[i]>=r) break;
            int mid=(l+r)/2;
            int op=upper_bound(f+1,f+1+k,mid-d[i])-f;
            int op1=f[op]+d[i];
            if(op1>=l&&op1<=r) ans=min(ans,max(max(r-op1,op1-l),pre));
            if(op==1) continue;
            int op2=f[op-1]+d[i];
            if(op2>=l&&op2<=r) ans=min(ans,max(max(r-op2,op2-l),pre));
        }

        cout<<ans<<endl;
    }

    return 0;
}