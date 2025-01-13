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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int t;
int a[N];
int l[N];
int g[N];

int f[4*N];

void pushup(int x){
    f[x]=min(f[x<<1],f[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return f[x]=0,void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void change(int x,int l,int r,int o,int v){
    if(l==r) return f[x]+=v,void();
    int mid=(l+r)>>1;
    if(o<=mid) change(x<<1,l,mid,o,v);
    else change(x<<1|1,mid+1,r,o,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return f[x];
    int mid=(l+r)>>1,res=0x3f3f3f3f3f3f3f;
    if(ql<=mid) res=min(res,query(x<<1,l,mid,ql,qr));
    if(qr>mid) res=min(res,query(x<<1|1,mid+1,r,ql,qr));
    return res;
}

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),g[i]=0,l[i]=0;
        read(m);
        for(int i=1;i<=m;i++){
            int a,b;
            read(a),read(b);
            if(!l[b]) l[b]=a;
            else l[b]=max(a,l[b]);
        }

        build(1,1,n);

        for(int i=1,j=0;i<=n;i++){
            change(1,1,n,i,g[i-1]+a[i]);
            if(l[i]&&l[i]>j) g[i]=query(1,1,n,l[i],i),j=l[i];
            else g[i]=g[i-1];
            // cout<<g[i]<<" ";
        }
        // cout<<endl;

        // for(int i=1;i<=n;i++) cout<<query(1,1,n,i,i)<<" ";
        // cout<<endl;

        cout<<g[n]<<endl;
    }

    return 0;
}