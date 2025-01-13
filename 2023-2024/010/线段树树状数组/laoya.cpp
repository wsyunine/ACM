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

int m,val;
int n;
int e[N],ne[N],idx,h[N];
int dfn[N],rev[N],siz[N],son[N],top[N],cnt=0;
int f[N],d[N];
vector<array<int,3>> p(N);

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    siz[x]=1;d[x]=d[fa]+1;
    son[x]=0;f[x]=fa;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[son[x]]<siz[j]) son[x]=j;
    }
}

void dfs2(int x,int fa){
    top[x]=fa,dfn[x]=++cnt,rev[cnt]=x;
    if(son[x]) dfs2(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==f[x]||j==son[x]) continue;
        dfs2(j,j);
    }
}

ll t1[N],t2[N],t3[N],t4[N],tag[N];

void build(int x,int l,int r){
    if(l==r) return t1[x]=t3[x]=(l==1)?val:0,t2[x]=-1,t4[x]=0x3f3f3f3f,void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x); 
}

void pushup(int x){
    if(t1[x<<1]>=t1[x<<1|1]){
        t1[x]=t1[x<<1];
        t2[x]=max(t2[x<<1],t1[x<<1|1]);
    }else{
        t1[x]=t1[x<<1|1];
        t2[x]=max(t2[x<<1|1],t1[x<<1]);
    }
    if(t3[x<<1]>=t3[x<<1|1]){
        t3[x]=t3[x<<1|1];
        t4[x]=min(t3[x<<1],t4[x<<1|1]);
    }else{
        t3[x]=t3[x<<1];
        t4[x]=min(t4[x<<1],t3[x<<1|1]);
    }
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    t1[x<<1]+=tag[x];
    t1[x<<1|1]+=tag[x];
    if(t2[x<<1]!=-1) t2[x<<1]+=tag[x];
    if(t2[x<<1|1]!=-1) t2[x<<1|1]+=tag[x];
    t3[x<<1]+=tag[x];
    t3[x<<1|1]+=tag[x];
    if(t4[x<<1]!=0x3f3f3f3f) t4[x<<1]+=tag[x];
    if(t4[x<<1|1]!=0x3f3f3f3f) t4[x<<1|1]+=tag[x];
    tag[x<<1]+=tag[x];
    tag[x<<1|1]+=tag[x];
    tag[x]=0;
}

void change(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r) return t1[x]=t3[x]=v,t4[x]=0x3f3f3f3f,t2[x]=-1,void();
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr,v);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

array<int,4> query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return {t1[x],t2[x],t3[x],t4[x]};
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    array<int,4> res,xx,yy;
    if(qr<=mid) return query(x<<1,l,mid,ql,qr);
    else if(ql>mid) return query(x<<1|1,mid+1,r,ql,qr);
    else{
        xx=query(x<<1,l,mid,ql,qr);
        yy=query(x<<1|1,mid+1,r,ql,qr);
        if(xx[0]>=yy[0]){
            res[0]=xx[0];
            res[1]=max(xx[1],yy[0]);
        }else{
            res[0]=yy[0];
            res[1]=max(yy[1],xx[0]);
        }
        if(xx[2]>=yy[2]){
            res[2]=yy[2];
            res[3]=max(xx[2],yy[3]);
        }else{
            res[2]=xx[2];
            res[3]=max(yy[2],xx[3]);
        }
        return res;
    }
}

void change_line(int x,int y,int v){
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]) swap(x,y);
        int tx=top[x],ty=top[y];
        change(1,1,n,dfn[tx],dfn[x],v);
        x=f[tx];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    change(1,1,n,dfn[x],dfn[y],v);
}

int main(){

    read(m);read(val);
    n=1;
    for(int i=1;i<=m;i++){
        read(p[i][0]);
        if(p[i][0]==1){
            n++;
            read(p[i][1]);
            read(p[i][2]);
            add(n,p[i][1]);
            add(p[i][1],n);
        }else{
            read(p[i][1]);
        }
    }

    dfs1(1,1);
    build(1,1,n);

    for(int i=1;i<=m;i++){
        if(p[i][0]==1){
            change_line(1,p[i][1],p[i][2]);
        }else if(p[i][0]==2){
            change_line(1,p[i][1],0);
        }
    }

    return 0;
}