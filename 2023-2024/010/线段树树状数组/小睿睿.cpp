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

int e[N],ne[N],h[N],idx;
int n;
int val[N],siz[N],son[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int yz[N];
void dfs1(int x,int fa){

}

void dfs2(int x,int fa){

}

int main(){

    for(int i=1;i<=100000;i++){
        
    }

    read(n);
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++) read(val[i]);


    
    return 0;
}