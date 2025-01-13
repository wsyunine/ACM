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

int n;
int t;
int e[N],ne[N],h[N],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dis[N][N];
bool vis[N];


void dij(int st){

}

int f[N];
int find(int x){
    return x==f[x]?f[x]:f[x]=find(f[x]);
}
void merge(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        f[a]=b;
    }

    add(a,b);add(b,a);
}

int main(){
    double a,b,c,d;
    while(1){
        cin>>a>>b>>c>>d;
        cout<<a*0.2+b*0.1+c*0.25+d*0.1<<endl;
    }

    return 0;
}