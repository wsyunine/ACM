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

const int Mod=2<<31;

int q;
struct node{
    int n,m,a;
}k[N];

int t[N];
int f[N];

void add(int x,int y,int n){
    for(;x<=n;x<<=1) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x>>=1) res+=t[x];
    return res;
}

bool cmp(node x,node y){
    return x.a<y.a;
}

int pri[N],cnt=0,mindiv[N],miu[N],sig[N];

void getth(int x){
    miu[1]=1;
    
}

int main(){

    read(q);
    for(int i=1;i<=q;i++){
        read(k[i].n),read(k[i].m),read(k[i].a);
    }

    sort(k+1,k+1+q,cmp);

    for(int i=1;i<=q;i++){

    }

    return 0;
}