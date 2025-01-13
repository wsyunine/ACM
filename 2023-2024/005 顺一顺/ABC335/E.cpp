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
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int s[N];
int e[N],idx,ne[N],h[N];
int dist[N],vis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    memset(dist,0x3f,sizeof dist);
}

int main(){

    memset(h,-1,sizeof h);
    read(n),read(m);

    for(int i=1;i<=n;i++) read(s[i]);
    for(int i=1;i<=m;i++){
        int x,y;
        read(x),read(y);
        if(s[x]>s[y]) swap(x,y);
        add(x,y);
        if(s[x]==s[y]) add(y,x);
    }



    return 0;
}