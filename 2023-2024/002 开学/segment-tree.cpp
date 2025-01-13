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

int t[4*N],tag[4*N],a[N];

void pushup(int x){
    t[x]=t[x<<1]+t[x<<1|1];
}

void build(int x,int l,int r){
    if(l==r) return t[x]=a[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    int mid=(l+r)>>1;
    t[x<<1]+=(mid-l+1)*tag[x];
    tag[x<<1]+=tag[x];
    t[x<<1|1]+=(r-mid)*tag[x];
    tag[x<<1|1]+=tag[x];
    tag[x]=0;
}


int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    int mid=(l+r)>>1,ret=0;
    pushdown(x,l,r);
    if(ql<=mid) ret+=query(x<<1,l,mid,ql,qr);
    if(qr>=mid+1) ret+=query(x<<1|1,mid+1,r,ql,qr);
    return ret;
}

void change(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&r<=cr){
        t[x]+=(r-l+1)*v;
        tag[x]+=v;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr,v);
    if(cr>=mid+1) change(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

signed main(){

    int n,m;
    read(n),read(m);

    for(int i=1;i<=n;i++) read(a[i]);

    build(1,1,n);

    for(int i=1;i<=m;i++){
        int opt,x,y,k;
        read(opt);
        if(opt==1){
            read(x),read(y),read(k);
            change(1,1,n,x,y,k);
        }else{
            read(x),read(y);
            cout<<query(1,1,n,x,y)<<endl;
        }
    }

    return 0;
}