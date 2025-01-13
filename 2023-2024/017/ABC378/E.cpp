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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

void print(__int128 x){
	if(x<0) putchar('-'),x=-x;
	if(x>9)	print(x/10);
	putchar(x%10+'0');
}

ll n,m;
ll a[N];
pair<ll,int> b[N];
__int128 res=0;

ll t[3][N];

void add(int x,ll y,int id){
    for(;x<=n;x+=x&(-x)) t[id][x]+=y;
}

ll query(int x,int id){
    ll res=0;
    for(;x;x-=x&(-x)) res+=t[id][x];
    return res;
}

signed main(){

    // freopen("Edata.in","r",stdin);
    // freopen("test.out","w",stdout);

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) a[i]=(a[i-1]+a[i])%m,b[i]={a[i],i},res+=a[i];

    sort(b+1,b+1+n);

    for(int i=1;i<=n;i++){
        //cout<<b[i].first<<" "<<b[i].second<<endl;
        ll cntl=query(b[i].second,0),suml=query(b[i].second,1);
        ll cntr=i-1-cntl,sumr=query(n,1)-query(b[i].second,1);
        res=res+(cntl*b[i].first-suml)+(cntr*m+sumr-cntr*b[i].first);
        //cout<<cntl<<" "<<cntr<<" "<<suml<<" "<<sumr<<" "<<endl;
        add(b[i].second,1,0),add(b[i].second,b[i].first,1);
    }

    print(res);
    cout<<endl;

    return 0;
}