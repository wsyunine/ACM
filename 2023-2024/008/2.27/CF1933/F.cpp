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

struct node{
    int x,y,t,f;
    node(int x,int y,int t,int f) : x(x),y(y),t(t),f(f) {}
};

int t;
int n,m;
int mapp[1010][1010];
map<node,int> p; 

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        queue<node> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) read(mapp[i][j]);
        }

        q.push(node(0,0,0,0));
        p[node(0,0,0,0)]=0;
        while(!q.empty()){
            node pos=q.front();
            q.pop();
            
        }
    }

    return 0;
}