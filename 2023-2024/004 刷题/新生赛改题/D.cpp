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

int n,c,m,k;
int a[N],dp[5010];

int main(){

    read(n),read(c),read(m),read(k);

    m=min(m,n);
    for(int i=1;i<=c;i++) read(a[i]);

    dp[0]=1;
    for(int i=1;i<=c;i++){
        if(a[i]>k) continue;
        for(int j=m;j>=a[i];j--) dp[j]=dp[j-a[i]]|dp[j];
    }

    for(int i=m;i>=0;i--) if(dp[i]){cout<<i<<endl;break;}
    
    return 0;
}