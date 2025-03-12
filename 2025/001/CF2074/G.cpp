#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n;
int a[N];
int dp[410][410];

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=0;
    for(int i=1;i+3-1<=n;i++) dp[i][i+3-1]=a[i]*a[i+1]*a[i+2];
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
            }
            for(int k=i+1;k<j;k++){
                int op=0;
                if(i+1<=k-1) op+=dp[i+1][k-1];
                if(k+1<=j-1) op+=dp[k+1][j-1];
                op+=a[i]*a[j]*a[k];
                dp[i][j]=max(dp[i][j],op);
            }
            if(i+1<=j-2) dp[i][j]=max(dp[i][j],dp[i+1][j-2]+a[i]*a[j]*a[j-1]);
            if(i+2<=j-1) dp[i][j]=max(dp[i][j],dp[i+2][j-1]+a[i]*a[j]*a[i+1]);
            if(i+3<=j) dp[i][j]=max(dp[i][j],dp[i+3][j]+a[i]*a[i+1]*a[i+2]);
            if(i<=j-3) dp[i][j]=max(dp[i][j],dp[i][j-3]+a[j-2]*a[j-1]*a[j]);
        }
    }

    cout<<dp[1][n]<<endl;

}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}