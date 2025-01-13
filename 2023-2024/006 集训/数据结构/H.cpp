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

int T;
int n,m,a[N],t[N];
pair<int,int> q[N];

void pushup(int x){
    t[x]=t[x<<1]*t[x<<1|1]%m;
}

void build(int x,int l,int r){
    if(l==r) return t[x]=a[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void modify(int x,int l,int r,int p){
    if(l==r) return t[x]=1,void();
    int mid=(l+r)>>1;
    if(p<=mid) modify(x<<1,l,mid,p);
    else modify(x<<1|1,mid+1,r,p);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    int mid=(l+r)>>1,res=1;
    if(ql<=mid) (res*=query(x<<1,l,mid,ql,qr))%=m;
    if(qr>mid) (res*=query(x<<1|1,mid+1,r,ql,qr))%=m;
    return res;
}

signed main(){

    read(T);
    while(T--){
        memset(t,0,sizeof t);
        read(n),read(m);
        for(int i=1;i<=n;i++) read(q[i].first),read(q[i].second);
        
        for(int i=1;i<=n;i++){
            if(q[i].first==1) a[i]=q[i].second;
            else a[i]=1;
        }

        build(1,1,n);

        for(int i=1;i<=n;i++){
            if(q[i].first==1){
                printf("%lld\n",query(1,1,n,1,i));
            }else{
                modify(1,1,n,q[i].second);
                printf("%lld\n",query(1,1,n,1,i));
            }
        }
    }

    return 0;
}