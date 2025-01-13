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

int n,q;
int e[N],ne[N],idx,h[N];
int d[N],dfn[N],cnt=0,rev[N],siz[N];
int top[N],f[N],son[N];
int ans[N];

struct node{
    int p,s,id;
    vector<int> u;
}qu[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool cmp(node x,node y){
    return dfn[x.p]<dfn[y.p];
}

ll t[4*N],tag[4*N];

void pushup(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return t[x]=d[rev[l]],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    t[x<<1]+=tag[x];
    t[x<<1|1]+=tag[x];
    tag[x<<1]+=tag[x];
    tag[x<<1|1]+=tag[x];
    tag[x]=0;
}

void change(int x,int l,int r,int cl,int cr,int v){
    if(cl>cr) return;
    if(cl<=l&&cr>=r) return t[x]+=v,tag[x]+=v,void();
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr,v);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

int jump(int x,int y){
    while(top[x]!=top[y]){
        y=top[y];
        if(f[y]==x) return y;
        else y=f[y];  
    }
    return son[x];
}

void dfs1(int x,int fa){
    f[x]=fa;son[x]=0;
    d[x]=d[fa]+1;dfn[x]=++cnt;rev[cnt]=x;siz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[j]>siz[son[x]]) son[x]=j;
    }
}

int pos=1;

void dfs2(int x,int fa){
    while(qu[pos].p==x){
        for(int i=0;i<qu[pos].s;i++){
            if(dfn[x]>=dfn[qu[pos].u[i]]&&dfn[x]<dfn[qu[pos].u[i]]+siz[qu[pos].u[i]]){
                int u=jump(qu[pos].u[i],x);
                change(1,1,n,1,dfn[u]-1,-n);
                change(1,1,n,dfn[u]+siz[u],n,-n);
            }else change(1,1,n,dfn[qu[pos].u[i]],dfn[qu[pos].u[i]]+siz[qu[pos].u[i]]-1,-n);
        }
        ans[qu[pos].id]=t[1];
        for(int i=0;i<qu[pos].s;i++){
            if(dfn[x]>=dfn[qu[pos].u[i]]&&dfn[x]<dfn[qu[pos].u[i]]+siz[qu[pos].u[i]]){
                int u=jump(qu[pos].u[i],x);
                change(1,1,n,1,dfn[u]-1,n);
                change(1,1,n,dfn[u]+siz[u],n,n);
            }else change(1,1,n,dfn[qu[pos].u[i]],dfn[qu[pos].u[i]]+siz[qu[pos].u[i]]-1,n);
        }
        pos++;
    }
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        change(1,1,n,1,n,1);
        change(1,1,n,dfn[j],dfn[j]+siz[j]-1,-2);
        dfs2(j,x);
        change(1,1,n,dfn[j],dfn[j]+siz[j]-1,2);
        change(1,1,n,1,n,-1);
    }
}

void dfs3(int x,int fa){
    top[x]=fa;
    if(son[x]) dfs3(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==f[x]||j==son[x]) continue;
        dfs3(j,j);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n);
    read(q);

    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }

    dfs1(1,1);
    dfs3(1,1);
    build(1,1,n);

    for(int i=1;i<=q;i++){
        read(qu[i].p);
        read(qu[i].s);
        qu[i].id=i;
        for(int j=1,l;j<=qu[i].s;j++){
            read(l);
            qu[i].u.push_back(l);
        }
    }

    sort(qu+1,qu+1+q,cmp);

    dfs2(1,1);

    for(int i=1;i<=q;i++) cout<<ans[i]-1<<endl;

    return 0;
}