#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 1000010
using namespace std;

int h[N],e[N],ne[N],v[N],idx;
int dist[N],cnt[N];
bool st[N];
int n,m;

void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],v[idx]=c,h[a]=idx++;
}

bool spfa(){

    memset(cnt,0,sizeof(cnt));
    memset(dist,N,sizeof(dist));
    queue<int> q;
    q.push(1);
    st[1]=1;
    dist[1]=0;
    for(int i=2;i<=n;i++) st[i]=0;

    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+v[i]){
                dist[j]=dist[t]+v[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>n) return 1;
                if(!st[j]){
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }

    return 0;

}

int main(){

    int t,u,v,w;
    cin>>t;
    while(t--){
        idx=0;
        memset(h,-1,sizeof(h));
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
            if(w>=0) add(v,u,w),add(u,v,w);
            else add(u,v,w);
        }

        if(spfa()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}