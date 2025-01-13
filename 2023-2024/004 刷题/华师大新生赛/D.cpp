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

int n,m,a[N];
ll ans=0;
int e[N],ne[N],h[N],idx,v[N];
ll d[100010][101];
int s[100010][101];

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],v[idx]=c,h[a]=idx++;
}

void dfs1(int x,int fa){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        if(d[x][v[i]]<d[j][v[i]]+(ll)a[x]){
            d[x][v[i]]=d[j][v[i]]+(ll)a[x];
            s[x][v[i]]=j;
        }
        ans=max(ans,d[x][v[i]]);
    }
}

void dfs2(int x,int fa){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
        if(j==s[x][v[i]]) continue;
        ans=max(ans,d[j][v[i]]+d[x][v[i]]);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) d[i][j]=a[i];
    }

    for(int i=1;i<n;i++){
        int a,b,c;
        read(a),read(b),read(c);
        add(a,b,c);
        add(b,a,c);
    }

    dfs1(1,0);
    dfs2(1,0);

    cout<<ans<<endl;

    return 0;
}