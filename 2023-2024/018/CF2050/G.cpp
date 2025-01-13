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

int t;
int n;
int e[N],ne[N],h[N],idx;
int dp[N],st,l[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    int op=0;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        op++;
    }
    if(op==0) st=x;
}

void dfs2(int x,int fa){
    int op=0;l[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
        op++;
    }
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        if(op-1+dp[j]>dp[x]){
            dp[x]=op-1+dp[j];
            l[x]=l[j]+1;
        }
        if(op==1){
            l[x]=l[j]+1;
        }
    }
    // cout<<x<<" "<<dp[x]<<" "<<l[x]<<endl;
}

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) h[i]=-1,dp[i]=0;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b);
            add(b,a);
        }

        dfs1(1,1);
        dfs2(st,st);

        if(l[st]>2) cout<<dp[st]+2<<endl;
        else cout<<dp[st]+1<<endl;
    }

    return 0;
}