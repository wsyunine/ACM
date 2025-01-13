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

int n,m,mapp[101][101],dp[101][101];
int t;

int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(mapp[i][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) dp[i][j]=mapp[i][j];
                else if(i==1) dp[i][j]=gcd(dp[i][j-1],mapp[i][j]);
                else if(j==1) dp[i][j]=gcd(dp[i-1][j],mapp[i][j]);
                else dp[i][j]=max(gcd(dp[i][j-1],mapp[i][j]),gcd(dp[i-1][j],mapp[i][j]));
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[n][m]<<endl;
    }

    return 0;
}