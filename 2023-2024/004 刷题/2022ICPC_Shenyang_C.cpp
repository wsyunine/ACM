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

int n,d;
int a[N],ans=0;

signed main(){

    read(n),read(d);
    for(int i=1;i<=n;i++) read(a[i]);

    int l,r;
    for(int i=1;i<=n;i++){
        l=a[i];r=l+d;
        int ss,s,cnt=0;
        if(a[1]<l) ss=l;
        else if(a[1]>r) ss=r;
        else ss=a[1];
        for(int j=2;j<=n;j++){
            if(a[j]<l) s=l;
            else if(a[j]>r) s=r;
            else s=a[j];
            cnt+=abs(ss-s);
            ss=s;
        }
        ans=max(ans,cnt);

        cnt=0;
        r=a[i];l=r-d;
        if(a[1]<l) ss=l;
        else if(a[1]>r) ss=r;
        else ss=a[1];
        for(int j=2;j<=n;j++){
            if(a[j]<l) s=l;
            else if(a[j]>r) s=r;
            else s=a[j];
            cnt+=abs(ss-s);
            ss=s;
        }
        ans=max(ans,cnt);
    }
    
    cout<<ans<<endl;

    return 0;
}