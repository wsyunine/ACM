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

int t;
int n,q;
int e[N],ne[N],h[N],idx;
ll w[N];
ll d[N];
int cw[64][N];

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

void dfs(int x,int fa){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        d[j]=d[x]^w[i];
        dfs(j,x);
    }
}

void init(){
    for(int i=1;i<=n;i++){
        int dw=0;
        ll opt=d[i];
        while(opt){
            cw[dw][i]=opt%2;
            opt>>=1;
            dw++;
        }
    }
    for(int i=0;i<=30;i++){
        for(int j=1;j<=n;j++){
            cw[i][j]=cw[i][j]+cw[i][j-1];
            // cout<<cw[i][j]<<" ";
        }
        // cout<<endl;
    }
}

ll solve(int l,int r,ll x){
    ll dop=1,res=0;x=d[x];
    for(int i=0;i<=30;i++,x/=2){
        // cout<<x%2<<endl;
        if(x%2){
            res+=dop*(r-l+1-(cw[i][r]-cw[i][l-1]));
        }else{
            res+=dop*(cw[i][r]-cw[i][l-1]);
        }
        dop*=2;
    }
    return res;
}

int main(){

    read(t);
    while(t--){
        memset(h,-1,sizeof h);
        memset(cw,0,sizeof cw);
        read(n);
        idx=0;
        for(int i=1;i<n;i++){
            int x,y,z;
            read(x),read(y),read(z);
            add(x,y,z),add(y,x,z);
        }
        d[1]=0;
        dfs(1,0);
        // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
        // cout<<endl;
        init();
        read(q);
        for(int i=1;i<=q;i++){
            int l,r,x;
            read(l),read(r),read(x);
            printf("%lld\n",solve(l,r,x));
        }
    }

    return 0;
}