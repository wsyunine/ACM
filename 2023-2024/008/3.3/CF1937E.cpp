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
#define pii pair<int,int>
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int t;
int c[N];
int e[N],ne[N],h[N],idx;
ll w[N];
ll dis[N];
bool vis[N];
pair<int,int> s[N];

void add(int a,int b,int c){
    // cout<<a<<" "<<b<<" "<<c<<endl;
    dis[a]=1e18,dis[b]=1e18;
    vis[a]=vis[b]=0;
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

int dij(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(make_pair(0,1));
    dis[1]=0;
    while(!q.empty()){
        pii op=q.top();
        q.pop();
        if(vis[op.second]) continue;
        vis[op.second]=1;
        for(int i=h[op.second];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[op.second]+w[i]){
                dis[j]=dis[op.second]+w[i];
                q.push(make_pair(dis[j],j));
            }
        }
    }
    if(dis[n]==1e18) return -1;
    return dis[n];
}

int main(){

    read(t);
    while(t--){
        idx=0;
        read(n),read(m);
        for(int i=1;i<=n;i++) read(c[i]);
        for(int i=1;i<=n*(m+1);i++) h[i]=-1;
        vector<vector<int>> mapp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                read(mapp[i][j]);
            }
        }

        for(int i=n+1,j=1;i<=n*(m+1);i++){
            add(i,(i-1)%n+1,c[(i-1)%n+1]);
            add((i-1)%n+1,i,0);
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) s[j].first=mapp[j][i],s[j].second=j;
            sort(s+1,s+1+n);
            for(int j=1;j<n;j++){
                add(n*i+s[j].second,n*i+s[j+1].second,0);
                add(n*i+s[j+1].second,n*i+s[j].second,s[j+1].first-s[j].first);
            }
        }

        int ans=dij();
        cout<<ans<<endl;
    }

    return 0;
}