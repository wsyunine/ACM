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
#define N 900010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,cnt=0,idea=0;
int e[N],ne[N],h[N],idx;
int vis[N],d[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int fa,int x){
    vis[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa){idea=1;return;}
        if(vis[j]){idea=1;return;}
        dfs(x,j);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n);
    map<string,int> p;

    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(p.find(s1)==p.end()) p[s1]=++cnt;
        if(p.find(s2)==p.end()) p[s2]=++cnt;
        add(p[s1],p[s2]);
        d[p[s2]]++;
    }

    vector<int> op;
    for(int i=1;i<=cnt;i++) vis[i]=0,(d[i]==0)?op.push_back(i):void();

    for(auto i:op){
        dfs(0,i);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){cout<<"No"<<endl;return 0;}
    }

    cout<<"Yes"<<endl;

    return 0;
}