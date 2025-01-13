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

int n,m,p;
int a[N],t[N];
int tag1[N],tag2[N];

void pushup(int x){
    t[x]=(t[x<<1]+t[x<<1|1])%p;
}

void build(int x,int l,int r){
    tag1[x]=1;
    if(l==r) return t[x]=a[l],tag1[x]=1,void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(tag1[x]!=1){
        (t[x<<1]*=tag1[x])%=p;
        (t[x<<1|1]*=tag1[x])%=p;
        (tag1[x<<1]*=tag1[x])%=p;
        (tag1[x<<1|1]*=tag1[x])%=p;
        (tag2[x<<1]*=tag1[x])%=p;
        (tag2[x<<1|1]*=tag1[x])%=p;
        tag1[x]=1;
    }
    if(tag2[x]){
        int mid=(l+r)>>1;
        (t[x<<1]+=(mid-l+1)*tag2[x]%p)%=p;
        (t[x<<1|1]+=(r-mid)*tag2[x]%p)%=p;
        (tag2[x<<1]+=tag2[x])%=p;
        (tag2[x<<1|1]+=tag2[x])%=p;
        tag2[x]=0;
    }
}

void add(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r){
        (tag2[x]+=v)%=p;
        (t[x]+=v*(r-l+1)%p)%=p;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) add(x<<1,l,mid,cl,cr,v);
    if(cr>mid) add(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

void time(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r){
        (tag2[x]*=v)%=p;
        (tag1[x]*=v)%=p;
        (t[x]*=v)%=p;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) time(x<<1,l,mid,cl,cr,v);
    if(cr>mid) time(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    pushdown(x,l,r);
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) (res+=query(x<<1,l,mid,ql,qr))%=p;
    if(qr>mid) (res+=query(x<<1|1,mid+1,r,ql,qr))%=p;
    return res;
}

signed main(){

    read(n),read(m),read(p);
    for(int i=1;i<=n;i++) read(a[i]);

    build(1,1,n);

    for(int i=1;i<=m;i++){
        int opt,x,y,k;
        read(opt);read(x),read(y);
        if(opt==1){
            read(k);
            time(1,1,n,x,y,k);
        }else if(opt==2){
            read(k);
            add(1,1,n,x,y,k);
        }else{
            printf("%lld\n",query(1,1,n,x,y));
        }
    }

    return 0;
}