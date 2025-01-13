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
#define N 1000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N];

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    
    int u=1,ans=0;
    while(1){
        ans=0;
        for(int i=1;i<=n;i++) ans+=(a[i]/u);
        if(ans==0||ans%2==1) break;
        u=u*2;
    }
    ans=0;
    for(int i=1;i<=n;i++) ans+=(a[i]/u+1)/2;

    cout<<ans<<endl;

    return 0;
}