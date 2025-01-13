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
string s;
int dp[N][5],dd[N][5],ans=0;

int main(){

    read(n);
    cin>>s;

    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        dp[i][3]=dp[i-1][3];
        dp[i][4]=dp[i-1][4];

        if(s[i-1]=='k'){
            dp[i][1]=dp[i-1][4]+1;
        }
        if(s[i-1]=='i'&&dp[i-1][1]){
            dp[i][2]=dp[i-1][1]+1;
        }
        if(s[i-1]=='r'&&dp[i-1][2]){
            dp[i][3]=dp[i-1][2]+1;
        }
        if(s[i-1]=='a'&&dp[i-1][3]){
            dp[i][4]=dp[i-1][3]+1;
        }
    }

    for(int i=n;i>=1;i--){
        dd[i][1]=dd[i+1][1];
        dd[i][2]=dd[i+1][2];
        dd[i][3]=dd[i+1][3];
        dd[i][4]=dd[i+1][4];

        if(s[i-1]=='i'){
            dd[i][1]=dd[i+1][4]+1;
        }
        if(s[i-1]=='k'&&dd[i+1][1]){
            dd[i][2]=dd[i+1][1]+1;
        }
        if(s[i-1]=='o'&&dd[i+1][2]){
            dd[i][3]=dd[i+1][2]+1;
        }
        if(s[i-1]=='d'&&dd[i+1][3]){
            dd[i][4]=dd[i+1][3]+1;
        }
    }

    for(int i=1;i<=n;i++){
        if(dp[i][4]&&dd[i][4]) ans=max(ans,dp[i][4]+dd[i][4]);
    }

    cout<<ans<<endl;

    return 0;
}