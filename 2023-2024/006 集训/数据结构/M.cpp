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

int n,m,a[N],d[N],siz[N],num[N];
int tp[N],tmm[N];
int e[N],ne[N],h[N],idx=0;
vector<int> dfn;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void add_p(int x,int y){
    for(;x<=n;x+=x&(-x)) tp[x]+=y;
}

void add_m(int x,int y){
    for(;x<=n;x+=x&(-x)) tmm[x]+=y;
}

int query_p(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=tp[x];
    return res;
}

int query_m(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=tmm[x];
    return res;
}

void dfs(int x,int fa,int dep){
    dfn.push_back(x);
    num[x]=dfn.size()-1;
    d[x]=dep;siz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x,dep+1);
        siz[x]+=siz[j];
    }
}

int main(){
    memset(h,-1,sizeof h);
    dfn.push_back(0);

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<n;i++){
        int x,y;
        read(x),read(y);
        add(x,y);add(y,x);
    }

    dfs(1,0,1);

    for(int i=1;i<=m;i++){
        int opt,x,y;
        read(opt);read(x);
        if(opt==1){
            read(y);
            if(d[x]%2){
                add_p(num[x],y);
                add_p(num[x]+siz[x],-y);
            }else{
                add_m(num[x],y);
                add_m(num[x]+siz[x],-y);
            }
        }else{
            if(d[x]%2){
                printf("%d\n",a[x]+query_p(num[x])-query_m(num[x]));
            }else{
                printf("%d\n",a[x]-query_p(num[x])+query_m(num[x]));
            }
        }
    }
    
    return 0;
}