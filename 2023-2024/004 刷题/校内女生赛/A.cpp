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
int mapp[N][3];
int dp[N][3];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(mapp[i][0]),read(mapp[i][1]),read(mapp[i][2]);

    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][1]+mapp[i][1],dp[i-1][2]+mapp[i][2]);
        dp[i][1]=max(dp[i-1][0]+mapp[i][0],dp[i-1][2]+mapp[i][2]);
        dp[i][2]=max(dp[i-1][1]+mapp[i][1],dp[i-1][0]+mapp[i][0]);
    }

    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;

    return 0;
}