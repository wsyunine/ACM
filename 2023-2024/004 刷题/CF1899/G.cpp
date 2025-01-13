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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,q;
int e[N],ne[N],h[N],idx;
int p[N],num[N];
int tr[N],op_t=0,n_t,dfn[N];
int put[N];

void add_t(int a,int b){
    if(a==0) return;
    for(;a<=n;a+=a&(-a)) tr[a]+=b;
}

int query(int a){
    int res=0;
    for(;a;a-=a&(-a)) res+=tr[a];
    return res;
}

struct node{
    int l,r,x,op;
    bool ans;
}qq[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa){
    dfn[x]=++op_t;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
    }
}

bool cmp(node a,node b){
    return dfn[a.x]<dfn[b.x];
}

void dfs2(int x,int fa){
    add_t(num[x],1);
    while(qq[n_t].x==x){
        if(query(qq[n_t].r)-query(qq[n_t].l-1)>0) qq[n_t].ans=1;
        else qq[n_t].ans=0;
        n_t++;
    }
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
    }
    add_t(num[x],-1);
}

int main(){

    
    memset(h,-1,sizeof h);
    read(n),read(q);
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++) read(p[i]),num[p[i]]=i;
    for(int i=1;i<=q;i++){
        read(qq[i].l),read(qq[i].r),read(qq[i].x);
        qq[i].op=i;
    }

    dfs(1,0);

    sort(qq+1,qq+1+q,cmp);

    n_t=1;
    dfs2(1,0);

    for(int i=1;i<=q;i++) put[qq[i].op]=qq[i].ans;
    for(int i=1;i<=q;i++){
        if(put[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}