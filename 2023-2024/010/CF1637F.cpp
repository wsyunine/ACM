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

int n;
ll hh[N];
int e[N],h[N],ne[N],idx;
ll siz[N],ee[N],emax[N],ep[N],f[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    siz[x]=1;f[x]=fa;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
    }
}

void dfs2(int x,int fa){
    if(siz[x]==1) ep[x]=x,emax[x]=hh[x],ee[x]=hh[x];
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
        if(emax[j]>emax[x]) emax[x]=ee[ep[j]],ep[x]=ep[j];
    }
    if(emax[x]<hh[x]) ee[ep[x]]=hh[x],emax[x]=hh[x];
}

int main(){

    memset(h,-1,sizeof h);

    read(n);
    int rt=0;
    for(int i=1;i<=n;i++) read(hh[i]),hh[i]>hh[rt]?rt=i:0;

    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b);add(b,a);
    }

    dfs1(rt,rt);
    dfs2(rt,rt);
    
    ll em1=0,ep1=rt,em2=0,ep2=0;
    for(int i=h[rt];~i;i=ne[i]){
        int j=e[i];
        if(emax[j]>em1) em2=em1,ep2=ep1,em1=ee[ep[j]],ep1=ep[j];
        else if(emax[j]>em2) em2=ee[ep[j]],ep2=ep[j];
    }
    // cout<<ep1<<" "<<ep2<<endl;
    if(ee[ep1]<hh[rt]){
        ee[ep1]=ee[ep2]=hh[rt];
    }else if(ee[ep2]<hh[rt]){
        ee[ep2]=hh[rt];
    }
    

    ll res=0;
    for(int i=1;i<=n;i++) res+=ee[i];
    cout<<res<<endl;

    return 0;
}