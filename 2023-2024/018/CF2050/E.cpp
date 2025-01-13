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

int t;
int n;
string a,b,c;
int dp[1010][1010];

int main(){

    read(t);
    while(t--){
        cin>>a>>b>>c;
        int sa=a.length(),sb=b.length();
        a=' '+a;
        b=' '+b;
        c=' '+c;

        for(int i=0;i<=sa;i++) for(int j=0;j<=sb;j++) dp[i][j]=0x3f3f3f3f;

        dp[0][0]=0;
        if(a[1]==c[1]) dp[1][0]=0;
        else dp[1][0]=1;
        if(b[1]==c[1]) dp[0][1]=0;
        else dp[0][1]=1;
        for(int i=0;i<=sa;i++){
            for(int j=0;j<=sb;j++){
                if(i&&a[i]==c[i+j]){
                    dp[i][j]=min(dp[i-1][j],dp[i][j]);
                }
                if(j&&b[j]==c[i+j]){
                    dp[i][j]=min(dp[i][j-1],dp[i][j]);
                }
                if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        cout<<dp[sa][sb]<<endl;
    }

    return 0;
}