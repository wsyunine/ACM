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

int n;
int v[N];
int e[N],ne[N],h[N],idx;
int m;
int son[N],siz[N];
vector<pair<int,int>> q[N];
int ans[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int t[N];

void addt(int x,int y){
    for(;x<=1e6;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

void dfs1(int x,int fa){
    siz[x]=1;
    son[x]=0;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[son[x]]<siz[j]) son[x]=j;
    }
}

void ope(int x,int fa,int op){
    addt(v[x],op);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        ope(j,x,op);
    }
}

void dfs2(int x,int fa){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[x]) continue;
        dfs2(j,x);
        ope(j,x,-1);
    }
    if(son[x]) dfs2(son[x],x);
    addt(v[x],1);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||j==son[x]) continue;
        ope(j,x,1);
    }
    for(auto i:q[x]){
        ans[i.second]=query(i.first);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n);
    for(int i=1;i<=n;i++) read(v[i]);
    for(int i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }

    dfs1(1,1);

    read(m);
    for(int i=1;i<=m;i++){
        int a,b;
        read(a),read(b);
        q[a].push_back(make_pair(b,i));
    }
    
    dfs2(1,1);

    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;

    return 0;
}