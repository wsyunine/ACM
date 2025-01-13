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
#define N 100010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,p[N];
vector<int> e[110];
int cl[N],mx[110],dmx=0;

// int n,p[N];
// int e[N],ne[N],h[N],idx;
// int mx=1,dm=1;
// int ch[N];
// vector<int> po;
// int cl[110];

// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }

// void dfs(int fa,int x,int d,int ds){
//     mx=max(mx,ds);
//     dm=max(dm,d);
//     for(int i=h[x];~i;i=ne[i]){
//         int j=e[i];
//         if(j==fa) continue;
//         if(ch[x]!=1&&ch[j]==1) po.push_back(j);
//         if(ch[x]==1&&x!=1) dfs(x,j,d+1,ds+1);
//         else dfs(x,j,d+1,0);
//     }
// }

// void dfs2(int fa,int x,int d){
//     if(cl[x]==-1) cl[x]=d;
//     for(int i=h[x];~i;i=ne[i]){
//         int j=e[i];
//         if(j==fa) continue;
//         dfs2(x,j,d+1);
//     }
// }

void dfs1(int x,int c){
    cl[x]=c;dmx=max(dmx,c);
    for(auto i:e[x]){
        if(e[x].size()==1) dfs1(i,c%3+1);
        else{
            if(c!=1) dfs1(i,1);
            else dfs1(i,2);
        }
    }
}

int main(){

    read(n);
    for(int i=2;i<=n;i++) read(p[i]),e[p[i]].push_back(i);

    for(int i=0;i<e[1].size();i++){
        dmx=1;
        dfs1(e[1][i],1);
        if(dmx==1){mx[i]=1;continue;}
        else if(dmx==2){mx[i]=2;continue;}
        else{
            dmx=2;
            dfs1(e[1][i],2);
            if(dmx==2) mx[i]=2;
            else mx[i]=3;
        }
    }

    for(int i=0;i<e[1].size();i++) dmx=max(dmx,mx[i]);

    cout<<dmx<<endl;
    for(int i=2;i<=n;i++) cout<<cl[i]<<" ";
    cout<<endl;

    int op;
    read(op);
    while(op==0){
        int tmp=0;
        for(int i=1,o=1;i<=dmx;i++,o*=2){
            int a;
            read(a);
            if(a==1) tmp+=o;
        }
        if(tmp==1||tmp==3) cout<<1<<endl;
        else if(tmp==2||tmp==6) cout<<2<<endl;
        else cout<<3<<endl;
        read(op);
    }

    // memset(h,-1,sizeof h);

    // read(n);
    // for(int i=1;i<=n;i++) cl[i]=-1;
    // for(int i=2;i<=n;i++){
    //     read(p[i]);
    //     add(i,p[i]),add(p[i],i);
    //     ch[p[i]]++;
    // }

    // dfs(0,1,1,0);

    // // cout<<mx<<" "<<dm<<endl;

    // if(dm==2){

    //     cout<<1<<endl;
    //     for(int i=2;i<=n;i++) cout<<1<<" ";
    //     cout<<endl;

    //     fflush(stdout);

    //     cout<<1<<endl;

    //     fflush(stdout);
        
    // }else{
    //     mx=max(mx+1,2);

    //     cout<<mx<<endl;

    //     for(auto i:po) dfs2(p[i],i,1);

    //     dfs2(p[1],1,0);

    //     for(int i=2;i<=n;i++) cout<<cl[i]<<" ";
    //     cout<<endl;

    //     fflush(stdout);

    //     int op;
    //     read(op);
    //     vector<int> k(mx+1);
    //     while(op==0){
    //         for(int i=1;i<=mx;i++) cin>>k[i];
    //         for(int i=1;i<=mx;i++){
    //             if(k[i]==1){cout<<i<<endl;break;}
    //         }
    //         read(op);

    //         fflush(stdout);
    //     }
    // }

    

    return 0;
}