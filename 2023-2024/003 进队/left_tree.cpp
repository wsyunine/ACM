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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int a[N];

int f[N],ls[N],rs[N],dis[N];

void init(){
    for(int i=1;i<=n;i++) f[i]=i;
}

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}

void merge_(int &p,int x,int y){
    if(!x||!y) return p=x+y,void();
    if(a[x]>a[y]) swap(x,y);
    merge_(rs[x],rs[x],y);
    f[rs[x]]=x;
    if(dis[ls[x]]<dis[rs[x]]) swap(ls[x],rs[x]);
    dis[x]=dis[rs[x]]+1;
    p=x;
}

void del(int x){
    x=find(x);
    a[x]=-1;
    f[ls[x]]=ls[x];
    f[rs[x]]=rs[x];
    merge_(f[x],ls[x],rs[x]);
}

int top(int x){
    return a[find(x)];
}

int merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) merge_(x,x,y);
    return x;
}

signed main(){

    read(n),read(m);
    init();

    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=m;i++){
        int opt,x,y,rt;
        read(opt);
        if(opt==1){
            read(x),read(y);
            if(a[x]==-1||a[y]==-1) continue;
            merge(x,y);
        }else{
            read(x);
            if(a[x]==-1){printf("-1\n");continue;}
            printf("%lld\n",top(x));
            del(x);
        }
    }

    return 0;
}