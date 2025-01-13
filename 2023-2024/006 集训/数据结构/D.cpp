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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int a[N],q[N],t[N];

void add(int x,int y){
    for(;x<=n;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

signed main(){

    read(n),read(m);
    for(int i=1;i<=n;i++)  read(a[i]),q[i]=a[i]-a[i-1],add(i,q[i]);

    for(int i=1;i<=m;i++){
        int opt,x,y,k;
        read(opt);
        if(opt==1){
            read(x),read(y),read(k);
            add(x,k);add(y+1,-k);
        }else{
            read(x);
            printf("%lld\n",query(x));
        }
    }

    return 0;
}