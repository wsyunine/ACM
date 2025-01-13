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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,p,ans=0;

int e[N],ne[N],h[N],idx;

int vis[N],mt[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(vis[j]) continue;
        vis[j]=1;
        if(mt[j]==0||find(mt[j])){mt[j]=x;return 1;}
    }
    return 0;
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m),read(p);

    for(int i=1;i<=p;i++){
        int a,b;
        read(a),read(b);
        add(a,b);
    }

    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(find(i)) ans++;
    }

    cout<<ans<<endl;

    return 0;
}