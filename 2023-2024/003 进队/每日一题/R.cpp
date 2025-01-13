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
#define N 300010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k;
int a[N],vis[N];

int main(){

    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]),(a[i]<=300000)?vis[a[i]]=1:0;

    int ans=0;
    while(vis[ans]&&ans<k) ans++;

    cout<<ans<<endl;

    return 0;
}