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
int e[N],ne[N],h[N],idx,mxd=0,ans=0;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa,int d){
    mxd=max(mxd,d);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x,d+1);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n);
    for(int i=1;i<=n-1;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }

    for(int i=h[1];~i;i=ne[i]){
        int j=e[i];
        mxd=0;
        dfs(j,1,1);
        ans+=mxd;
    }

    cout<<ans<<endl;
    
    return 0;
}