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

int dm[2],dd[2];
vector<int> pace(N),op(N);

void dfs(int x,int fa,int d,int id){
    op[d]=x;
    if(d>dm[id]) dm[id]=d,dd[id]=x,pace=op;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x,d+1,id);
    }
}

int main(){

    read(t);
    while(t--){
        memset(h,-1,sizeof h);
        read(n);
        dm[0]=dm[1]=0,dd[0]=dd[1]=0;

        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
            pace[i]=0,op[i]=0;
        }
        pace[n]=op[n]=0;

        dfs(1,1,1,0);
        for(int i=1;i<=n;i++) op[i]=0;
        dfs(dd[0],dd[0],1,1);

        int res=0;
        if(dm[1]%2){
            res=(dm[1]+1)/2;
            cout<<(dm[1]+1)/2<<endl;
            for(int i=0;i<res;i++){
                cout<<pace[(dm[1]+1)/2]<<" "<<i<<endl;
            }
        }else if(dm[1]%4){
            res=dm[1]/2+1;
            cout<<dm[1]/2+1<<endl;
            for(int i=1;i<=res/2;i++){
                cout<<pace[dm[1]/2]<<" "<<2*i-1<<endl;
            }
            for(int i=1;i<=res/2;i++){
                cout<<pace[dm[1]/2+1]<<" "<<2*i-1<<endl;
            }
        }else{
            res=dm[1]/2;
            cout<<dm[1]/2<<endl;
            for(int i=1;i<=res/2;i++){
                cout<<pace[dm[1]/2]<<" "<<2*i-1<<endl;
            }
            for(int i=1;i<=res/2;i++){
                cout<<pace[dm[1]/2+1]<<" "<<2*i-1<<endl;
            }
        }
    }

    return 0;
}