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
const int Mod=1e9+7;

int t;
int n;
int m;
int a[N];
int b[N];
int w[N];
int e[2*N],ne[2*N],idx,h[N];
int d[N],dd[N],inv[N],ans[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

void dfs(int x,int fa,int oo){
    dd[x]=dd[fa]+1;
    if(fa) ans[x]=(oo?inv[dd[x]]:0);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x,oo);
    }
}

signed main(){
    inv[0]=1;
    for(int i=1;i<=500000;i++) inv[i]=inv[i-1]*i%Mod;
    for(int i=1;i<=500000;i++) inv[i]=fpow(inv[i],Mod-2);
    read(t);
    while(t--){
        read(n);
        idx=0;
        for(int i=1;i<=n;i++) read(a[i]),h[i]=-1,ans[i]=0,d[i]=0,dd[i]=0;
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=1;i<=n;i++) read(w[i]);

        for(int i=1;i<=n;i++){
            if(a[b[i]]<=a[i]&&a[b[i]]+w[b[i]]>a[i]){
                if(i!=b[i]){
                    add(i,b[i]);
                    add(b[i],i);
                    d[i]++;
                }else{
                    ans[i]=a[i];
                }
            }else if(a[b[i]]>a[i]){
                ans[i]=(a[i]+w[i])%Mod;
            }else{
                ans[i]=a[i];
            }
        }

        for(int i=1;i<=n;i++){
            if(!d[i]) dfs(i,0,(ans[i]==(a[i]+w[i])));
        }

        for(int i=1;i<=n;i++){
            if(d[i]) ans[i]=(a[i]+ans[i]*w[i]%Mod)%Mod;
        }

        for(int i=1;i<=n;i++){
            if(!ans[i]) ans[i]=a[i];
        }
        
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
/*

4
4
2 5 5 2
4 2 1 3
3 2 1 4
3
5 4 3
1 1 1
6 6 6
3
5 4 3
2 3 1
1 2 3
5
2 1 3 2 1
5 1 1 3 4
1 3 4 2 4


*/