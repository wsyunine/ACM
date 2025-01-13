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

int n;
int t;
int e[N],ne[N],h[N],idx;

struct node{
    int a,b,c,d;
    node(int a,int b,int c,int d): a(a),b(b),c(c),d(d) {};
};
vector<node> p;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int rt,dm=0,ans=0;

void dfs1(int x,int fa,int d){
    if(dm<d) dm=d,rt=x;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x,d+1);
    }
}

int son[N],d[N],md[N],f[N];

void dfs2(int x,int fa){
    son[x]=0;d[x]=d[fa]+1;md[x]=d[x];f[x]=fa;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
        if(md[son[x]]<md[j]) son[x]=j;
        md[x]=max(md[x],md[j]);
    }
}

void dfs3(int x,int fa){
    if(son[x]) dfs3(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==f[x]||j==son[x]) continue;
        ans++;
        p.push_back({j,f[j],j,rt}),rt=j;
        dfs3(j,j);
    }
}

int main(){

    read(t);
    while(t--){
        memset(h,-1,sizeof h);
        dm=0;ans=0;p.clear();
        read(n);
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }

        dfs1(1,1,1);
        dfs2(rt,rt);
        dfs3(rt,rt);

        cout<<ans<<endl;
        for(auto i:p){
            cout<<i.a<<" "<<i.b<<" "<<i.c<<" "<<i.d<<endl;
        }
        
    }

    return 0;
}