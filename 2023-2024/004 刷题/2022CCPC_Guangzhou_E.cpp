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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
pair<ll,int> s[N];
int t[N];
int cnt[N];
ll ans[N];

void add(int x,int y){
    if(x==0) return;
    for(;x<=n;x+=x&-x) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&-x) res+=t[x];
    return res;
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) t[i]=0,read(s[i].first),s[i].second=i;

    sort(s+1,s+1+n);

    for(int i=1;i<=n;i++){
        cnt[i]=query(s[i].second);
        add(s[i].second,1);
    }

    ll sum=0;
    for(int i=1;i<=n;i++){
        if((ll)cnt[i]+(ll)(i-1)*(ll)s[i].first-(ll)sum>m-2) ans[s[i].second]=-1;
        else ans[s[i].second]=(ll)cnt[i]+(ll)(i-1)*(ll)s[i].first-(ll)sum;
        sum+=s[i].first;
    }

    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);

    return 0;
}