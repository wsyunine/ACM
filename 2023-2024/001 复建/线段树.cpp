#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
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

int n,m,p;
int a[N];
int t[4*N],tag1[4*N],tag2[4*N];

void pushup(int x){
    t[x]=(t[x<<1]+t[x<<1|1])%p;
}

void pushdown(int x,int l,int r){
    if(tag2[x]!=1){
        (t[x<<1]*=tag2[x])%=p;
        (t[x<<1|1]*=tag2[x])%=p;
        (tag1[x<<1]*=tag2[x])%=p;
        (tag1[x<<1|1]*=tag2[x])%=p;
        (tag2[x<<1]*=tag2[x])%=p;
        (tag2[x<<1|1]*=tag2[x])%=p;
        tag2[x]=1;
    }
    if(tag1[x]){
        int mid=(l+r)>>1;
        (t[x<<1]+=tag1[x]*(mid-l+1))%=p;
        (t[x<<1|1]+=tag1[x]*(r-mid))%=p;
        (tag1[x<<1]+=tag1[x])%=p;
        (tag1[x<<1|1]+=tag1[x])%=p;
        tag1[x]=0;
    }
}

void build(int x,int l,int r){
    tag2[x]=1;
    if(l==r){t[x]=a[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void change_p(int x,int l,int r,int ql,int qr,int v){
    if(ql<=l&&qr>=r){(t[x]+=(r-l+1)*v)%=p,(tag1[x]+=v)%=p;return;}
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(ql<=mid) change_p(x<<1,l,mid,ql,qr,v);
    if(qr>mid) change_p(x<<1|1,mid+1,r,ql,qr,v);
    pushup(x);
}

void change_m(int x,int l,int r,int ql,int qr,int v){
    if(ql<=l&&qr>=r){(t[x]*=v)%=p,(tag2[x]*=v)%=p,(tag1[x]*=v)%=p;return;}
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(ql<=mid) change_m(x<<1,l,mid,ql,qr,v);
    if(qr>mid) change_m(x<<1|1,mid+1,r,ql,qr,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    int mid=(l+r)>>1,res=0;
    pushdown(x,l,r);
    if(ql<=mid) (res+=query(x<<1,l,mid,ql,qr))%=p;
    if(qr>mid) (res+=query(x<<1|1,mid+1,r,ql,qr))%=p;
    return res;
}

signed main(){

    read(n);read(m);read(p);
    for(int i=1;i<=n;i++) read(a[i]);
    build(1,1,n);

    for(int i=1;i<=m;i++){
        int opt,a,b,c;
        read(opt);
        if(opt==1){
            read(a),read(b),read(c);
            change_m(1,1,n,a,b,c);
        }else if(opt==2){
            read(a),read(b),read(c);
            change_p(1,1,n,a,b,c);
        }else{
            read(a),read(b);
            printf("%lld\n",query(1,1,n,a,b));
        }
    }


    return 0;
}
