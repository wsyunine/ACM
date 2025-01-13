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
#define N 200010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
string s;
int n,b[N][2],sum=0;
int dp[N][2];

int main(){

    read(t);
    while(t--){
        memset(dp,0,sizeof dp);
        cin>>s;
        n=s.size();
        int cnt=0;
        sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A') cnt++;
            else{
                b[++sum][0]=cnt;
                b[sum-1][1]=b[sum][0];
                cnt=0;
            }
        }
        b[sum][1]=cnt;
        
        dp[1][0]=b[1][0];
        dp[1][1]=b[1][1];
        for(int i=2;i<=sum;i++){
            dp[i][0]=max(dp[i][0],dp[i-1][0]+b[i][0]);
            dp[i][1]=max(dp[i][1],max(dp[i-1][1],dp[i-1][0])+b[i][1]);
        }

        cout<<max(dp[sum][0],dp[sum][1])<<endl;
    }

    return 0;
}