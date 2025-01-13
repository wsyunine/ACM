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

int n,m,p[N],ans=0;
int t;
int e[N],ne[N],idx,h[N],siz[N],f[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa){
    siz[x]=1;f[x]=fa;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
        siz[x]+=siz[j];
    }
    if(p[x]){
        ans+=siz[x]/2;
        if(siz[x]%2==0) p[f[x]]=1;
        siz[x]=0;
    }
}

int main(){

    read(t);
    while(t--){
        idx=0;ans=0;
        read(n);read(m);
        for(int i=0;i<=n;i++) h[i]=-1,p[i]=0;
        for(int i=1,k;i<=m;i++) read(k),p[k]=1;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b);
            add(b,a);
        }

        for(int i=1;i<=n;i++){
            if(p[i]){dfs(i,0);break;}
        }

        cout<<ans<<endl;
    }

    return 0;
}