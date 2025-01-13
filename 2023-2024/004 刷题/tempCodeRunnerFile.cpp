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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll n,x;
int mapp[2000010];

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(x),read(n);
    ll s=(1ll<<((int)floor(log2(x))+1));

    mapp[0]=0;
    for(ll i=1;i<=s;i++){
        mapp[i]=mapp[i-1]+(gcd((x*i)^x,x)==1ll);
    }

    for(int i=1;i<=n;i++){
        ll l,r;
        ll ans=0;
        read(l),read(r);
        ans+=(r-l+1)/s*(ll)mapp[s];
        l=(l-1)%s+1;r=(r-1)%s+1;
        if(l-1<=r) ans+=(ll)mapp[r]-(ll)mapp[l-1];
        else ans+=((ll)mapp[s]-(ll)mapp[l-1]+(ll)mapp[r]);
        printf("%lld\n",ans);
    }

    return 0;
}