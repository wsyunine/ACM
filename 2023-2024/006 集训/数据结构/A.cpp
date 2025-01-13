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

int n,m;
int a[N];
int lgn[N]={-1},f[N][30];

void init(){
    for(int i=1;i<=n;i++) f[i][0]=a[i],lgn[i]=lgn[i/2]+1;
    for(int j=1;j<=lgn[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int len=lgn[r-l+1];
    return max(f[l][len],f[r-(1<<len)+1][len]);
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);

    init();

    for(int i=1;i<=m;i++){
        int l,r;
        read(l),read(r);
        printf("%d\n",query(l,r));
    }

    return 0;
}