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
#define N 2000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int p[N];
int t[N],ta[N],tl[N],tr[N];

struct node{
    int s,sa,sl,sr;
    node(int s,int sa,int sl,int sr) : s(s),sa(sa),sl(sl),sr(sr) {}
};

void pushup(int x){
    t[x]=t[x<<1]+t[x<<1|1];
    ta[x]=max(tr[x<<1]+tl[x<<1|1],max(ta[x<<1],ta[x<<1|1]));
    tl[x]=max(tl[x<<1],t[x<<1]+tl[x<<1|1]);
    tr[x]=max(tr[x<<1|1],t[x<<1|1]+tr[x<<1]);
}

void build(int x,int l,int r){
    if(l==r) return t[x]=ta[x]=tl[x]=tr[x]=p[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void modify(int x,int l,int r,int pos,int v){
    if(l==r) return t[x]=ta[x]=tl[x]=tr[x]=v,void();
    int mid=(l+r)>>1;
    if(pos<=mid) modify(x<<1,l,mid,pos,v);
    else modify(x<<1|1,mid+1,r,pos,v);
    pushup(x);
}

node query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return node(t[x],ta[x],tl[x],tr[x]);
    int mid=(l+r)>>1;
    if(qr<=mid){
        return query(x<<1,l,mid,ql,qr);
    }else if(ql>mid){
        return query(x<<1|1,mid+1,r,ql,qr);
    }else{
        node a=query(x<<1,l,mid,ql,qr);
        node b=query(x<<1|1,mid+1,r,ql,qr);
        node c(a.s+b.s,max(max(a.sa,b.sa),a.sr+b.sl),max(a.sl,a.s+b.sl),max(b.sr,b.s+a.sr));
        return c;
    }
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) read(p[i]);

    build(1,1,n);

    for(int i=1;i<=m;i++){
        int k,x,y;
        read(k);read(x),read(y);
        if(k==1){
            if(x>y) swap(x,y);
            node ans=query(1,1,n,x,y);
            printf("%d\n",ans.sa);
        }else{
            modify(1,1,n,x,y);
        }
    }

    return 0;
}