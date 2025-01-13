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

int n,m;
int e[N],ne[N],idx,h[N];
ll val[N];
int l[N],cnt=0,r[N],len[N];
int son[N];
vector<array<int,3>> q[N];
vector<array<ll,3>> res(N);

ll ts[N],ti[N],ta[N];

void pushup(int x){
    ts[x]=ts[x<<1]+ts[x<<1|1];
    ta[x]=max(ta[x<<1],ta[x<<1|1]);
    ti[x]=min(ti[x<<1],ti[x<<1|1]);
}

void change(int x,int l,int r,int p,ll s,ll mx,ll mn){
    if(l==r){
        ts[x]+=s;
        ti[x]=min(ti[x],mn);
        ta[x]=max(ta[x],mx);
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) change(x<<1,l,mid,p,s,mx,mn);
    else change(x<<1|1,mid+1,r,p,s,mx,mn);
    pushup(x); 
}

array<ll,3> query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return {ts[x],ta[x],ti[x]};
    int mid=(l+r)>>1;
    array<ll,3> ans,xx,yy;
    if(qr<=mid) return query(x<<1,l,mid,ql,qr);
    else if(ql>mid) return query(x<<1|1,mid+1,r,ql,qr);
    else{
        xx=query(x<<1,l,mid,ql,qr);
        yy=query(x<<1|1,mid+1,r,ql,qr);
        ans={xx[0]+yy[0],max(xx[1],yy[1]),min(xx[2],yy[2])};
        return ans;
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        if(len[son[x]]<len[j]) son[x]=j;
    }
    len[x]=len[son[x]]+1;
}

void dfs2(int x,int fa){
    l[x]=++cnt;
    r[x]=l[x]+len[x]-1;
    if(son[x]) dfs2(son[x],x);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[x]) continue;
        dfs2(j,x);
    }
}

//在线段树上不断合并子树中的链
void dfs(int x,int fa){
    if(son[x]) dfs(son[x],x);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[x]) continue;
        dfs(j,x);
        for(int op1=l[j],op2=l[x]+1;op1<=r[j];op1++,op2++){
            array<ll,3> opt=query(1,1,n,op1,op1);
            change(1,1,n,op2,opt[0],opt[1],opt[2]);
        }
    }
    change(1,1,n,l[x],val[x],val[x],val[x]);
    for(auto i:q[x]){
        res[i[2]]=query(1,1,n,l[x]+i[0],l[x]+i[1]);
    }
}

int main(){

    memset(h,-1,sizeof h);
    memset(ti,0x3f,sizeof ti);

    read(n);
    for(int i=1;i<=n;i++) read(val[i]);
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    read(m);

    for(int i=1;i<=m;i++){
        int a,b,c;
        read(a),read(b),read(c);
        q[a].push_back({b,c,i});
    }

    dfs1(1,1);
    dfs2(1,1);
    dfs(1,1);

    for(int i=1;i<=m;i++) cout<<res[i][2]<<" "<<res[i][1]<<" "<<res[i][0]<<endl;

    return 0;
}