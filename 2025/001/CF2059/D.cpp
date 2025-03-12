#include<bits/stdc++.h>
using namespace std;
#define N 4000010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int a[1010][1010],b[1010][1010];
int e[N],ne[N],h[N],idx,vis[N];
int mapp[1010],dist[N];
int m1,m2,n,s1,s2;
vector<pair<int,int>> sa;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int num(int x,int y){
    return (x-1)*n+y;
}

int cost(int s,int t){
    int x2=t/n+1;
    int y2=t%n;
    if(y2==0) x2--,y2=n;
    return abs(x2-y2);
}

void solve() {
    sa.clear();
    read(n),read(s1),read(s2);
    read(m1);
    idx=0;
    for(int i=1;i<=n*n;i++) h[i]=-1,vis[i]=0,dist[i]=0x3f3f3f3f;

    for(int i=1;i<=n;i++){
        mapp[i]=0;
        for(int j=1;j<=n;j++){
            a[i][j]=b[i][j]=0;
        }
    }

    for(int i=1;i<=m1;i++){
        int x,y;
        read(x),read(y);
        a[x][y]=1;
        a[y][x]=1;
        sa.push_back({x,y});
    }
    read(m2);
    for(int i=1;i<=m2;i++){
        int x,y;
        read(x),read(y);
        b[x][y]=1;
        b[y][x]=1;
        for(auto j:sa){
            add(num(j.first,x),num(j.second,y));
            add(num(j.first,y),num(j.second,x));
            add(num(j.second,x),num(j.first,y));
            add(num(j.second,y),num(j.first,x));
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i][j]&&b[i][j]){
                mapp[i]=mapp[j]=1;
                // cout<<i<<" "<<j<<endl;
            }
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dist[num(s1,s2)]=0;
    q.push({0,num(s1,s2)});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int dis=t.first,ver=t.second;
        if(vis[ver]) continue;
        vis[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[ver]+cost(ver,j)){
                dist[j]=dist[ver]+cost(ver,j);
                q.push({dist[j],j});
            }
        }
    }

    int res=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(mapp[i]) res=min(res,dist[num(i,i)]);
    }
    if(res==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}