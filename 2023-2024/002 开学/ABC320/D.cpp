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
#define N 400010
#define ll long long
#define INF 1e18
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
pair<ll,ll> d[N];
int e[N],ne[N],h[N],idx,vis[N];
pair<ll,ll> v[N];
queue<int> q;
vector<int> topo;

void add(int a,int b,ll c,ll d){
    e[idx]=b,ne[idx]=h[a],v[idx]=make_pair(c,d),h[a]=idx++;
}

void dfs(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(vis[j]) continue;
        vis[j]=1;
        d[j].first=d[x].first+v[i].first;
        d[j].second=d[x].second+v[i].second;
        dfs(j);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m);

    for(int i=1;i<=n;i++) d[i]=make_pair(INF,INF);

    for(int i=1;i<=m;i++){
        ll a,b,c,d;
        read(a),read(b),read(c),read(d);
        add(a,b,c,d);
        add(b,a,-c,-d);
    }

    d[1]=make_pair(0,0);

    dfs(1);
    vis[1]=1;

    for(int i=1;i<=n;i++){
        if(d[i].first==INF) cout<<"undecidable"<<endl;
        else cout<<d[i].first<<" "<<d[i].second<<endl;
    }

    return 0;
}