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
int a[N];
int f[N];

int main(){

    memset(f,0x3f,sizeof f);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    f[1]=0;
    f[2]=abs(a[1]-a[2]);

    for(int i=3;i<=n;i++){
        f[i]=min(f[i-1]+abs(a[i-1]-a[i]),f[i-2]+abs(a[i-2]-a[i]));
    }

    cout<<f[n]<<endl;

    return 0;
}