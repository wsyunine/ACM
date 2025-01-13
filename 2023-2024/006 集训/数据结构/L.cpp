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
#define INF 1e9+7
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int m;
int a[N],t[32*N],ls[32*N],rs[32*N],siz=0,rt[N];
int lst[N],num[N];

int cpy(int x){
    rs[++siz]=rs[x];
    ls[siz]=ls[x];
    t[siz]=t[x];
    return siz;
}

void pushup(int x){
    if(lst[t[ls[x]]]<=lst[t[rs[x]]]){
        t[x]=t[ls[x]];
    }else{
        t[x]=t[rs[x]];
    }
}

void change(int &x,int l,int r,int pos,int v){
    x=cpy(x);
    if(l==r) return t[x]=v,void();
    int mid=(l+r)>>1;
    if(pos<=mid) change(ls[x],l,mid,pos,v);
    else change(rs[x],mid+1,r,pos,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    // cout<<l<<" "<<r<<endl;
    if(ql<=l&&qr>=r) return lst[t[x]]>=ql?0:t[x];
    int mid=(l+r)>>1,res=0;
    if(ql<=mid){
        res=query(ls[x],l,mid,ql,qr);
        if(lst[res]>=ql) res=0;
    }
    if(!res&&qr>mid){
        res=query(rs[x],mid+1,r,ql,qr);
        if(lst[res]>=ql) res=0;
    }
    return res;
}

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    lst[n+1]=INF;

    for(int i=1;i<=n;i++){
        if(num[a[i]]) lst[i]=num[a[i]];
        num[a[i]]=i;
        rt[i]=cpy(rt[i-1]);
        change(rt[i],1,n,i,i);
        if(lst[i]) change(rt[i],1,n,lst[i],n+1);
    }

    read(m);
    for(int i=1;i<=m;i++){
        int l,r;
        read(l),read(r);
        printf("%d\n",a[query(rt[r],1,n,l,r)]);
    }

    return 0;
}