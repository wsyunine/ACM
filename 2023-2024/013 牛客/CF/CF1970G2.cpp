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

int n,m,c;
int t;
int e[N],ne[N],idx,h[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){

    read(t);
    while(t--){
        read(n),read(m),read(c);

    }

    return 0;
}