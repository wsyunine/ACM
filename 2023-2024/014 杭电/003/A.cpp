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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const int Mod=998244353;

int n;
int t;
int dp[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    read(n);
    dp[0]=1,dp[1]=0;
    for(int i=1;i<=n;i++){
        (dp[i]+=dp[i-1])%=Mod;
        for(int j=2;j*i<=n;j++){
            (dp[j*i]+=dp[i-1])%=Mod;
        }
    }
    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;

    return 0;
}