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
#define N 800010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const int Mod=998244353;

int n;
pair<int,int> p[N];
int e[N],ne[N],h[N],idx;
int d[N],f[N],son[N],top[N],siz[N],dfn[N],rev[N],cnt=0;
ll ans=0;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    f[x]=fa;
    d[x]=d[fa]+1;siz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[son[x]]<siz[j]) son[x]=j;
    }
}

void dfs2(int x,int fa){
    top[x]=fa;dfn[x]=++cnt,rev[cnt]=x;
    if(son[x]) dfs2(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==f[x]||j==son[x]) continue;
        dfs2(j,j);
    }
}

bool cmp(pair<int,int> x,pair<int,int> y){return x.first>y.first;}

ll t[N],tag[N];

void pushup(int x){
    t[x]=(t[x<<1]+t[x<<1|1])%Mod;
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    int mid=(l+r)>>1;
    (t[x<<1]+=tag[x]*(ll)(mid-l+1))%=Mod;
    (t[x<<1|1]+=tag[x]*(ll)(r-mid))%=Mod;
    tag[x<<1]+=tag[x];
    tag[x<<1|1]+=tag[x];
    tag[x]=0;
}

void change(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r) return (t[x]+=(ll)(r-l+1))%=Mod,tag[x]++,void();
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr);
    pushup(x);
}

ll query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    ll mid=(l+r)>>1,res=0;
    pushdown(x,l,r);
    if(ql<=mid) (res+=query(x<<1,l,mid,ql,qr))%=Mod;
    if(qr>mid) (res+=query(x<<1|1,mid+1,r,ql,qr))%=Mod;
    return res;
}

void change_line(int x,int y){
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]) swap(x,y);
        int tx=top[x],ty=top[y];
        change(1,1,n,dfn[tx],dfn[x]);
        x=f[tx];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    change(1,1,n,dfn[x],dfn[y]);
}

ll query_line(int x,int y){
    ll res=0;
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]) swap(x,y);
        int tx=top[x],ty=top[y];
        (res+=query(1,1,n,dfn[tx],dfn[x]))%=Mod;
        x=f[tx];
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    (res+=query(1,1,n,dfn[x],dfn[y]))%=Mod;
    return res;
}

signed main(){

    memset(h,-1,sizeof h);

    read(n);
    for(int i=1;i<=n;i++) read(p[i].first),p[i].second=i;
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }

    dfs1(1,1);
    dfs2(1,1);

    sort(p+1,p+1+n,cmp);

    ll pos=d[p[1].second];
    change_line(1,p[1].second);
    for(ll i=2;i<=n;i++){
        ll res=(pos+(i-1ll)*d[p[i].second]-2*query_line(1,p[i].second)+Mod)%Mod;
        (ans+=p[i].first*res)%=Mod;
        change_line(1,p[i].second);
        (pos+=d[p[i].second])%=Mod;
    }

    cout<<ans*2%Mod<<endl;

    return 0;
}