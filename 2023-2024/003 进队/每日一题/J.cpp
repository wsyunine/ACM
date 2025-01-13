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
#define N 800010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int e[N],ne[N],h[N],idx;
int d[N];
int st=-1,ed=-1,cnt=0;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int fa,int x){
    cnt++;
    if(x==ed) return;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(x,j);
    }
}

int main(){

    memset(h,-1,sizeof h);

    read(n),read(m);
    for(int i=1;i<=m;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
        d[a]++;
        d[b]++;
    }

    if(m!=n-1){
        cout<<"No"<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        if(st==-1&&d[i]==1) st=i;
        else if(ed==-1&&d[i]==1) ed=i;
        else if(d[i]==1){cout<<"No"<<endl;return 0;}
        if(d[i]>2||d[i]<1){cout<<"No"<<endl;return 0;}
    }

    if(st==-1){cout<<"No"<<endl;return 0;}
    else if(ed==-1){cout<<"No"<<endl;return 0;}

    dfs(0,st);

    if(cnt!=n){cout<<"No"<<endl;return 0;} 

    cout<<"Yes"<<endl;

    return 0;
}