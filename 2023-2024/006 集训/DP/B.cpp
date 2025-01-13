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
int f[N];
int h[N],k;

int main(){

    memset(f,0x3f,sizeof f);
    read(n),read(k);
    for(int i=1;i<=n;i++) read(h[i]);
    f[1]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k&&i-j>=1;j++){
            f[i]=min(f[i],f[i-j]+abs(h[i-j]-h[i]));
        }
    }

    cout<<f[n]<<endl;

    return 0;
}