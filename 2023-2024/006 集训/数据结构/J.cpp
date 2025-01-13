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

int n,m;
int a[N],t[N][21],tag[N][21];

void pushup(int x){
    for(int i=0;i<=20;i++){
        t[x][i]=t[x<<1][i]+t[x<<1|1][i];
    }
}

void build(int x,int l,int r){
    if(l==r){
        int op=a[l];
        for(int i=0;i<=20;i++,op/=2){
            t[x][i]=op%2;
        }
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    for(int i=0;i<=20;i++){
        if(!tag[x][i]) continue;
        int mid=(l+r)>>1;
        tag[x<<1][i]^=tag[x][i];
        tag[x<<1|1][i]^=tag[x][i];
        t[x<<1][i]=(mid-l+1)-t[x<<1][i];
        t[x<<1|1][i]=(r-mid)-t[x<<1|1][i];
        tag[x][i]=0;
    }
}

void change(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r){
        int op=v;
        for(int i=0;i<=20;i++,op/=2){
            tag[x][i]^=op%2;
            if(op%2) t[x][i]=r-l+1-t[x][i];
        }
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr,v);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        int res=0;
        for(int i=0,j=1;i<=20;i++,j<<=1){
            res+=j*t[x][i];
            // cout<<x<<" "<<i<<" "<<t[x][i]<<endl;
        }
        return res;
    }
    int mid=(l+r)>>1,res=0;
    pushdown(x,l,r);
    if(ql<=mid) res+=query(x<<1,l,mid,ql,qr);
    if(qr>mid) res+=query(x<<1|1,mid+1,r,ql,qr);
    return res;
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    build(1,1,n);

    read(m);

    for(int i=1;i<=m;i++){
        int opt,l,r,x;
        read(opt);
        if(opt==1){
            read(l),read(r);
            printf("%lld\n",query(1,1,n,l,r));
        }else{
            read(l),read(r),read(x);
            change(1,1,n,l,r,x);
        }
    }

    return 0;
}