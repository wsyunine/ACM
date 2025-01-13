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
#define N 1500010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
ll a[N];

int main(){ 

    read(t);
    while(t--){
        read(n);
        a[0]=0;
        ll ans=0;
        for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];

        for(int i=1;i*i<=n;i++){
            if(n%i) continue;

            ll mn=0x3f3f3f3f3f3f3f3f,mx=0;

            for(int j=i;j<=n;j+=i){
                mn=min(mn,(ll)a[j]-a[j-i]);
                mx=max(mx,(ll)a[j]-a[j-i]);
            }
            ans=max(ans,mx-mn);

            mn=0x3f3f3f3f3f3f3f3f,mx=0;

            for(int j=n/i;j<=n;j+=n/i){
                mn=min(mn,(ll)a[j]-a[j-n/i]);
                mx=max(mx,(ll)a[j]-a[j-n/i]);
            }
            ans=max(ans,mx-mn);
        }
        cout<<ans<<endl;
    }

    return 0;
}