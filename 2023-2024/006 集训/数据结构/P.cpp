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
#define N 35010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int k,lst[N],num[N];
int a[N],t[32*N],f[N][55],tag[32*N];

void pushup(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}

void build(int x,int l,int r,int op){
    tag[x]=0;
    if(l==r) return t[x]=f[l][op],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid,op);
    build(x<<1|1,mid+1,r,op);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    tag[x<<1]+=tag[x];
    tag[x<<1|1]+=tag[x];
    t[x<<1]+=tag[x];
    t[x<<1|1]+=tag[x];
    tag[x]=0;
}

void change(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r){
        tag[x]+=1;
        t[x]+=1;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change(x<<1,l,mid,cl,cr);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    pushdown(x,l,r);
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res=max(res,query(x<<1,l,mid,ql,qr));
    if(qr>mid) res=max(res,query(x<<1|1,mid+1,r,ql,qr));
    pushup(x);
    return res;
}

int main(){

    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1,s=0;i<=n;i++){
        if(!num[a[i]]) s++;
        else lst[i]=num[a[i]];
        num[a[i]]=i;
        f[i][1]=s;
    }

    for(int j=2;j<=k;j++){
        build(1,1,n,j-1);
        for(int i=2;i<=n;i++){
            change(1,1,n,max(lst[i],1),i-1);
            if(j<=i) f[i][j]=query(1,1,n,1,i-1);
        }
    }

    cout<<f[n][k]<<endl;

    return 0;
}