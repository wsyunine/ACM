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
#define N 500010
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,S,T;
int e[N],ne[N],h[N],idx;
int wt[N],wl[N];
int vis[N],dist[N],disl[N];
int pret[N],prel[N];

void add(int a,int b,int c,int d){
    e[idx]=b,ne[idx]=h[a],wt[idx]=c,wl[idx]=d,h[a]=idx++;
}

int dijkstra_time(int st,int ed){
    memset(dist,0x3f,sizeof dist);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    dist[st]=0;
    q.push({0,st});
    while(q.size()){
        auto op=q.top();
        q.pop();
        int dis=op.first,ver=op.second;
        if(vis[ver]) continue;
        vis[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[ver]+wt[i]){
                dist[j]=dist[ver]+wt[i];
                pret[j]=ver;
                q.push({dist[j],j});
            }
        }
    }
    if(dist[ed]==0x3f) return -1;
    return dist[ed];
}

int dijkstra_length(int st,int ed){
    memset(disl,0x3f,sizeof disl);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    disl[st]=0;
    q.push({0,st});
    while(q.size()){
        auto op=q.top();
        q.pop();
        int dis=op.first,ver=op.second;
        if(vis[ver]) continue;
        vis[ver]=1;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(disl[j]>disl[ver]+wl[i]){
                disl[j]=disl[ver]+wl[i];
                prel[j]=ver;
                q.push({disl[j],j});
            }
        }
    }
    if(disl[ed]==0x3f) return -1;
    return disl[ed];
}

int main(){
    memset(h,-1,sizeof h);

    //输入城市及公路数量
    cout<<"请输入城市数量：";
    read(n);
    cout<<"请输入公路数量：";
    read(m);

    //输入公路参数
    cout<<"接下来请输入m行公路参数，格式为：城市1编号 城市2编号 预期平均行驶时间 实际里程"<<endl;
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        read(a),read(b),read(c),read(d);
        add(a,b,c,d);
        add(b,a,c,d);
    }

    cout<<"请输入起点：";
    read(S);
    cout<<"请输入终点：";
    read(T);

    int rest=dijkstra_time(S,T);
    if(rest==-1){
        cout<<S<<"与"<<T<<"不连通"<<endl;
        return 0;
    }
    vector<int> patht;
    int tmp=T;
    patht.push_back(T);
    while(tmp!=S){
        tmp=pret[tmp];
        patht.push_back(tmp);
    }
    reverse(patht.begin(),patht.end());

    cout<<"最短用时路径为："<<endl;
    for(auto i:patht){
        cout<<i<<((i==T)?"":"->");
    }
    cout<<endl;
    cout<<"最短用时为："<<rest<<endl;

    int resl=dijkstra_length(S,T);
    vector<int> pathl;
    tmp=T;
    pathl.push_back(T);
    while(tmp!=S){
        tmp=prel[tmp];
        pathl.push_back(tmp);
    }
    reverse(pathl.begin(),pathl.end());

    cout<<"最短里程路径为："<<endl;
    for(auto i:pathl){
        cout<<i<<((i==T)?"":"->");
    }
    cout<<endl;
    cout<<"最短距离为："<<resl<<endl;

    return 0;
}