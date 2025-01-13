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
#define N 400010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,r,p,rt;
int a[N];
int dfn[N],dep[N],rev[N],son[N],fat[N],top[N],cnt=0,siz[N];
int e[N],ne[N],h[N],idx;
ll t[N],tag[N];
int ls[N],rs[N];
int cntp=0;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    siz[x]=1,fat[x]=fa,dep[x]=dep[fa]+1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[j]>siz[son[x]]) son[x]=j;
    }
}

void dfs2(int x,int fa){
    dfn[x]=++cnt,rev[cnt]=x,top[x]=fa;
    if(son[x]) dfs2(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fat[x]||j==son[x]) continue;
        dfs2(j,j);
    }
}

void pushup(int x){
    t[x]=(t[ls[x]]+t[rs[x]])%p;
}

void build(int &x,int l,int r){
    x=++cntp;
    if(l==r) return t[x]=a[rev[l]]%p,void();
    int mid=(l+r)>>1;
    build(ls[x],l,mid);
    build(rs[x],mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    int mid=(l+r)>>1;
    (tag[rs[x]]+=tag[x])%=p;
    (tag[ls[x]]+=tag[x])%=p;
    (t[ls[x]]+=(ll)(mid-l+1)*tag[x]%p)%=p;
    (t[rs[x]]+=(ll)(r-mid)*tag[x]%p)%=p;
    tag[x]=0;
}

void modify(int x,int l,int r,int cl,int cr,ll v){
    if(l>=cl&&r<=cr) return (t[x]+=(ll)(r-l+1)*v%p)%=p,(tag[x]+=v)%=p,void();
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) modify(ls[x],l,mid,cl,cr,v);
    if(cr>mid) modify(rs[x],mid+1,r,cl,cr,v);
    pushup(x);
}

ll query(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr) return t[x];
    int mid=(l+r)>>1;
    ll res=0;
    pushdown(x,l,r);
    if(ql<=mid) (res+=query(ls[x],l,mid,ql,qr))%=p;
    if(qr>mid) (res+=query(rs[x],mid+1,r,ql,qr))%=p;
    return res%p;
}

void change(int x,int y,ll z){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        int tx=top[x],ty=top[y];
        modify(rt,1,n,dfn[tx],dfn[x],z);
        x=fat[tx];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    modify(rt,1,n,dfn[x],dfn[y],z);
}

ll ask(int x,int y){
    ll res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        int tx=top[x],ty=top[y];
        (res+=query(rt,1,n,dfn[tx],dfn[x]))%=p;
        x=fat[tx];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    (res+=query(rt,1,n,dfn[x],dfn[y]))%=p;
    return res%p;
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m),read(r),read(p);

    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b);
        add(b,a);
    }

    dfs1(r,0);
    dfs2(r,0);
    build(rt,1,n);

    // for(int i=1;i<=n;i++) cout<<dfn[i]<<" ";
    // cout<<endl;
    // cout<<query(rt,1,n,1,2);

    for(int i=1;i<=m;i++){
        ll opt,x,y,z;
        read(opt);
        if(opt==1){
            read(x),read(y),read(z);
            change(x,y,z);
        }else if(opt==2){
            read(x),read(y);
            cout<<ask(x,y)<<endl;
        }else if(opt==3){
            read(x),read(z);
            modify(rt,1,n,dfn[x],dfn[x]+siz[x]-1,z%p);
        }else{
            read(x);
            cout<<query(rt,1,n,dfn[x],dfn[x]+siz[x]-1)<<endl;
        }
    }

    return 0;
}

/*
5 5 2 24
7 3 7 8 0 
1 2
1 5
3 1
4 1
3 4 2
3 2 2
4 5
1 5 1 3
2 1 3

2
21


8 10 2 448348
458 718 447 857 633 264 238 944 
1 2
2 3
3 4
6 2
1 5
5 7
8 6
3 7 611
4 6
3 1 267
3 2 111
1 6 3 153
3 7 673
4 8
2 6 1
4 7
3 4 228
*/