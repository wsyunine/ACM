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

int n,x;
int a[N],b[N];
bool dp[10010];

int main(){

    read(n),read(x);

    for(int i=1;i<=n;i++) read(a[i]),read(b[i]);

    for(int i=1;i<=x;i++) dp[i]=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=x;j>=1;j--){
            for(int k=1;k<=b[i];k++){
                if(j<k*a[i]) continue;
                dp[j]=dp[j-k*a[i]]|dp[j];
                // cout<<j<<" "<<j-k*a[i]<<" "<<dp[j-k*a[i]]<<endl;
            }
        }
    }

    // for(int i=0;i<=x;i++) cout<<dp[i]<<" ";
    // cout<<endl;

    if(dp[x]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}