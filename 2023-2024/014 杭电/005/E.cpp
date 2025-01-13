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
#define N 1000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
int e[2*N],ne[2*N],h[N],idx,id[2*N];
int f[N],par[N],d[N],ed[N],ans[N];

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],id[idx]=c,h[a]=idx++;
}

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

void dfs(int x,int fa){
    par[x]=fa;d[x]=d[fa]+1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
        ed[j]=id[i];
    }
}

int main(){
    int size(256<<20); //256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));

    read(t);
    while(t--){
        read(n);idx=0;
        for(int i=1;i<=n;i++) h[i]=-1,f[i]=i;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b,i);add(b,a,i);
        }
        dfs(1,0);
        for(int i=n/2;i>0;i--){
            int opi=find(i);
            for(int j=i+i;j<=n;j+=i){
                int opj=find(j);
                while(opi!=opj){
                    if(d[opi]<d[opj]) swap(opi,opj);
                    ans[ed[opi]]=i;
                    f[opi]=find(par[opi]);
                    opi=find(par[opi]);
                }
            }
        }
        for(int i=1;i<n-1;i++) cout<<ans[i]<<" ";
        cout<<ans[n-1]<<endl;
    }

    exit(0);
}