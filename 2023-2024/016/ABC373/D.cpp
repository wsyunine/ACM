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


int n,m;
int e[N],ne[N],h[N],w[N],idx,d[N],vis[N];
vector<int> topo;
long long ans[N];

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void dfs(int x,int fa,long long num){
    vis[x]=1;
    ans[x]=num;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||vis[j]) continue;
        dfs(j,x,num+(long long)w[i]);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        read(a),read(b),read(c);
        add(b,a,-c);
        add(a,b,c);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0,0);
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}