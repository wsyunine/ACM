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
#define ll unsigned long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
// const ll Mod=(1<<64);

int n,e[2*N],ne[2*N],h[N],idx;
ll a[N];
ll s[N],sq[N],ans[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

ll cnt[40*N],sum[40*N];
int ls[40*N],rs[40*N],rt[40*N],cnt_node=0;

int n_node(int l,int r){
    int x=++cnt_node;
    return x;
}

void pushup(int x){
    cnt[x]=cnt[ls[x]]+cnt[rs[x]];
    sum[x]=sum[ls[x]]+sum[rs[x]];
}

void change(int &x,int l,int r,ll p){
    if(!x) x=n_node(l,r);
    if(l==r){
        cnt[x]++;
        sum[x]+=p*p;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) change(ls[x],l,mid,p);
    else change(rs[x],mid+1,r,p);
    pushup(x);
}

int merge(int x,int y,int l,int r,ll &ans){
    if(!x) return y;
    if(!y) return x;
    if(l==r){
        ans+=2*cnt[x]*sum[y];
        sum[x]+=sum[y];
        cnt[x]+=cnt[y];
        return x;
    }
    int mid=(l+r)>>1;
    sum[x]+=sum[y];
    cnt[x]+=cnt[y];
    ans+=2*cnt[ls[x]]*sum[rs[y]];
    ans+=2*cnt[ls[y]]*sum[rs[x]];
    ls[x]=merge(ls[x],ls[y],l,mid,ans);
    rs[x]=merge(rs[x],rs[y],mid+1,r,ans);
    return x;
}

void dfs(int x,int fa){
    s[x]=a[x];
    sq[x]=a[x]*a[x];
    change(rt[x],1,1e6,a[x]);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
        s[x]+=s[j];
        sq[x]+=sq[j];
        rt[x]=merge(rt[x],rt[j],1,1e6,sq[x]);
    }
    // cout<<x<<" "<<sum[x]<<" "<<sq[x]<<" ";
    ans[x]=sq[x]-s[x]*s[x];
    // cout<<ans[x]<<endl;
}


int main(){

    memset(h,-1,sizeof h);
    read(n);
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++) read(a[i]);
    dfs(1,0);

    ll res=0;
    for(int i=1;i<=n;i++){
        // cout<<ans[i]<<endl;
        res^=ans[i];
    }
    cout<<res<<endl;

    return 0;
}