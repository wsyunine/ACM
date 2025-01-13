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
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int a[N];
int rt[N];
int ls[32*N],rs[32*N],t[32*N],siz=0;

int cpy(int x){
    ls[++siz]=ls[x];
    rs[siz]=rs[x];
    t[siz]=t[x];
    return siz;
}

void build(int &x,int l,int r){
    x=++siz;
    if(l==r) return t[x]=a[l],void();
    int mid=(l+r)>>1;
    build(ls[x],l,mid);
    build(rs[x],mid+1,r);
}

void change(int &x,int l,int r,int pos,int v){
    x=cpy(x);
    if(l==r) return t[x]=v,void();
    int mid=(l+r)>>1;
    if(pos<=mid) change(ls[x],l,mid,pos,v);
    else change(rs[x],mid+1,r,pos,v);
}

int query(int x,int l,int r,int pos){
    if(l==r) return t[x];
    int mid=(l+r)>>1;
    if(pos<=mid) return query(ls[x],l,mid,pos);
    else return query(rs[x],mid+1,r,pos);
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);

    build(rt[0],1,n);

    for(int i=1;i<=m;i++){
        int opt,v,x,y;
        read(v),read(opt);
        rt[i]=rt[v];
        if(opt==1){
            read(x),read(y);
            change(rt[i],1,n,x,y);
        }else{
            read(x);
            printf("%d\n",query(rt[i],1,n,x));
        }
    }

    return 0;
}