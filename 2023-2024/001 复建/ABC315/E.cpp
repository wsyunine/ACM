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
using namespace std;
#define N 800010 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int ne[N],e[N],h[N],idx;
int d[N],q[N];
int hh=0,tt=-1;
int vis[N];
vector<int> topo,ans,mapp(N);

bool cmp(int a,int b){
    return mapp[a]>mapp[b];
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){

    cin>>n;
    memset(d,0,sizeof(d));
    memset(h,-1,sizeof(h));
    for(int i=1;i<=n;i++){
        int k;
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>k;
            add(i,k);
            d[k]++;
        } 
    }

    q[++tt]=1;
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(!vis[j]){
                q[++tt]=j;
                vis[j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++) if(vis[i]) ans.push_back(i);

    hh=0,tt=-1;
    for(int i=1;i<=n;i++) if(!d[i]) q[++tt]=i,topo.push_back(i);

    while(hh<=tt){
        int t=q[hh++];
        for (int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(--d[j]==0){
                q[++tt]=j;
                topo.push_back(j);
            }
        }
    }
    
    for(int i:topo) mapp[topo[i]]=i;

    sort(ans.begin(),ans.end(),cmp);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}