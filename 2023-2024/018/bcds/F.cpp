#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 500010
#define int long long

int e[N],ne[N],idx,h[N];

int n,t,m,a[N],b[N];
int vis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int s1,s2;
void dfs(int x,int fa){
    vis[x]=1;
    s1+=a[x],s2+=b[x];
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa||vis[j]) continue;
        dfs(j,x);
    }
}

signed main(){

    cin>>t;
    while(t--){
        cin>>n>>m;
        idx=0;
        for(int i=1;i<=n;i++) cin>>a[i],h[i]=-1,vis[i]=0;
        for(int i=1;i<=n;i++) cin>>b[i];

        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }

        int idea=1;
        for(int i=1;i<=n;i++){
            s1=s2=0;
            if(!vis[i]) dfs(i,0);
            if(s1!=s2) idea=0;
        }

        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}