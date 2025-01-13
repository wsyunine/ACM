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
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int t;
int dist[N],vis[N];
int u[N],s[N][7];

void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    dist[0]=0;
    q.push({0,0});
    while(q.size()){
        pii op=q.top();
        q.pop();
        int dis=op.first,ver=op.second;
        if(vis[ver]) continue;
        vis[ver]=1;
        // cout<<ver<<endl;
        vector<int> a(7),b(7);
        int op1=ver;
        for(int i=1;i<=n;i++){
            a[i]=op1%10;
            op1/=10;
        }
        // if(ver==99) cout<<a[3]<<endl;
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                b=a;
                for(int i=l;i<=r;i++) b[i]=(a[i]+1)%10;
                int x=0;
                for(int i=n;i>=1;i--) x=x*10+b[i];
                if(dist[x]>dist[ver]+1) dist[x]=dist[ver]+1,q.push({dist[x],x});
                b=a;
                for(int i=l;i<=r;i++) b[i]=(a[i]-1+10)%10;
                x=0;
                for(int i=n;i>=1;i--) x=x*10+b[i];
                if(dist[x]>dist[ver]+1) dist[x]=dist[ver]+1,q.push({dist[x],x});
            }
        }
    }
}

void spfa(){
    memset(dist,0x3f,sizeof dist);
    memset(vis,0,sizeof vis);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    dist[0]=0;
    while(!q.empty()){
        int op=q.front();
        q.pop();
        vis[op]=0;
        vector<int> a(7),b(7);
        int op1=op;
        for(int i=1;i<=n;i++){
            a[i]=op1%10;
            op1/=10;
        }
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                b=a;
                for(int i=l;i<=r;i++) b[i]=(a[i]+1)%10;
                int x=0;
                for(int i=n;i>=1;i--) x=x*10+b[i];
                if(dist[x]>dist[op]+1){
                    dist[x]=dist[op]+1;
                    if(!vis[x]) q.push(x),vis[x]=1;
                }
                b=a;
                for(int i=l;i<=r;i++) b[i]=(a[i]-1+10)%10;
                x=0;
                for(int i=n;i>=1;i--) x=x*10+b[i];
                if(dist[x]>dist[op]+1){
                    dist[x]=dist[op]+1;
                    if(!vis[x]) q.push(x),vis[x]=1;
                }
            }
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    dist[u]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                int v,tu;
                vector<int> a(7);
                tu=u;
                for(int i=n;i>=1;i--){
                    a[i]=tu%10;
                    tu/=10;
                }
                for(int i=l;i<=r;i++) a[i]=(a[i]+1)%10;
                v=0;
                for(int i=1;i<=n;i++) v=v*10+a[i];
                if(!dist[v]){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }

                tu=u;
                for(int i=n;i>=1;i--){
                    a[i]=tu%10;
                    tu/=10;
                }
                for(int i=l;i<=r;i++) a[i]=(a[i]+9)%10;
                v=0;
                for(int i=1;i<=n;i++) v=v*10+a[i];
                if(!dist[v]){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
    }
}

bool check(int x){
    int y=x;
    vector<int> a(7);
    int op=0;
    for(int i=1;i<=n;i++) a[i]=x%10,x/=10;
    for(int i=1;i<=m;i++){
        op=0;
        for(int j=n;j>=1;j--) op*=10,op+=(a[j]-s[i][j]+10)%10;
        // if(y==114) cout<<op<<" "<<dist[op]<<endl;
        // if(dist[op]>u[i]||((dist[op]-u[i])%2==1&&n==1)||(u[i]==1&&dist[op]==0))
        //     return 0;
        if(dist[op]>u[i] ||(dist[op]==0 && u[i]==1)||(n==1 && (u[i]-dist[op])%2==1))
            return 0;
    }
    return 1;
}

int main(){
    
    n=5;
    bfs(0);
    for(int i=0;i<=99999;i++){
        dist[i]--;
    }
    read(t);
    while(t--){
        read(n),read(m);
        // dijkstra();
        // spfa();
        
        for(int i=1;i<=m;i++) read(s[i][6]),read(u[i]);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) s[i][j]=s[i][6]%10,s[i][6]/=10;
        }
        // cout<<dist[99]<<endl;

        int sum=1;
        for(int i=1;i<=n;i++) sum*=10;
        sum--;
        int ans,cnt=0;
        
        for(int i=0;i<=sum;i++){
            if(check(i)) ans=i,cnt++;
        }
        string ss=to_string(ans);
        while(ss.length()<n) ss='0'+ss;
        if(cnt>1) cout<<"MANY"<<endl;
        else if(cnt==0) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ss<<endl;
    }

    return 0;
}