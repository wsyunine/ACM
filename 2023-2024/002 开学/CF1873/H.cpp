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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a,b;
int t;
int e[N],ne[N],h[N],idx=0;
int vis[N];
int rs=0;
int xx,yy;
int fr[N];
vector<int> r;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int fa,int x){
    vis[x]++;fr[x]=fa;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        if(vis[j]>1){
            rs=j;
            return;
        }
        dfs1(x,j);
    }
}

int dfs2(int fa,int x,int d){
    // cout<<x<<endl;
    // cout<<x<<endl;
    if(find(r.begin(),r.end(),x)!=r.end()){
        xx=x;
        return d;
    }
    int ans=-1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        ans=max(dfs2(x,j,d+1),ans);
    }
    return ans;
}

int dfs4(int fa,int x,int d){
    if(find(r.begin(),r.end(),x)!=r.end()){
        yy=x;
        return d;
    }
    int ans=-1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        ans=max(dfs4(x,j,d+1),ans);
    }
    return ans;
}

int main(){

    read(t);

    // if(t==1000){

    //     while(t--){
    //     memset(h,-1,sizeof h);
    //     idx=0;xx=0,yy=0;
    //     r.clear();
    //     read(n),read(a),read(b);
    //     cout<<n<<" "<<a<<" "<<b<<endl;
    //     for(int i=1;i<=n;i++){
    //         vis[i]=0;
    //         int x,y;
    //         read(x),read(y);
    //         if(t==975) cout<<x<<" "<<y<<endl;
    //     }

    //     // if(a==b){cout<<"NO"<<endl;continue;}

    //     dfs1(0,1);

    //     int op=rs;
    //     while(vis[op]!=0){
    //         vis[op]=0;
    //         r.push_back(op);
    //         op=fr[op];
    //     }

    //     // for(auto i:r) cout<<i<<endl;

    //     int l1=dfs2(0,b,0);

    //     int l2=dfs4(0,a,0);

    //     int op1=find(r.begin(),r.end(),xx)-r.begin(),op2=find(r.begin(),r.end(),yy)-r.begin();

    //     int u=abs(op1-op2),siz=r.size();

    //     l2+=min(u,siz-u);
    // }


    // }

    while(t--){
        memset(h,-1,sizeof h);
        idx=0;xx=0,yy=0;
        r.clear();
        read(n),read(a),read(b);
        for(int i=1;i<=n;i++){
            vis[i]=0;
            int x,y;
            read(x),read(y);
            add(x,y),add(y,x);
        }

        if(a==b){cout<<"NO"<<endl;continue;}

        dfs1(0,1);

        int op=rs;
        while(vis[op]!=0){
            vis[op]=0;
            r.push_back(op);
            op=fr[op];
        }

        // for(auto i:r) cout<<i<<endl;

        int l1=dfs2(0,b,0);

        int l2=dfs4(0,a,0);

        int op1=find(r.begin(),r.end(),xx)-r.begin(),op2=find(r.begin(),r.end(),yy)-r.begin();

        int u=abs(op1-op2),siz=r.size();

        l2+=min(u,siz-u);

        // cout<<xx<<" "<<yy<<endl;

        // cout<<op1<<" "<<op2<<" "<<siz<<endl;

        // cout<<l1<<" "<<l2<<endl;

        if(l2>l1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
/*

10 8 6
7 3
2 7
1 10
2 1
7 6
7 4
5 4
3 9
1 3
8 2

*/