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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k,res=0;
int a[N];
int t[N],f[N][11];

void add(int x,int y){
    for(;x<=n;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

signed main(){

    read(n),read(k);k++;

    for(int i=1;i<=n;i++) read(a[i]),f[i][1]=1;

    for(int j=2;j<=k;j++){
        for(int i=1;i<=n;i++) t[i]=0;
        for(int i=1;i<=n;i++){
            f[i][j]=query(a[i]-1);
            add(a[i],f[i][j-1]);
        }
    }

    for(int i=1;i<=n;i++) res+=f[i][k];

    cout<<res<<endl;

    return 0;
}