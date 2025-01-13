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
#define N 5005
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int m;
int q;

int C[N][N],dp[N][N];
int ans1=0,ans2=0;

int fpow(int a,int b,int p){
    int res=1%p;
    a%=p;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res;
}

void init(){
    C[1][0]=C[1][1]=1%q;
    for(int i=2;i<=5000;i++){
        C[i][0]=C[i][i]=1%q;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%q;
        }
    }

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m-1;j++){
            dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%q*i%q;
        }
    }
}

signed main(){

    read(n),read(m),read(q);
    init();

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=n;i++){
        int b=(fpow(2ll,i,q)-1ll+q)%q;
        b=fpow(b,m-1ll,q);
        (ans1+=C[n][i]*b%q*fpow(2ll,(m-1)*(n-i),q)%q)%=q;
    }

    for(int k=2;k<=n;k++){
        int opp=0;
        int c=((fpow(2,k,q)-1-k)%q+q)%q,d=1;
        for(int p=k,r=m-1;p<=m-1;p++,r--){
            // cout<<op<<endl;
            (opp+=dp[k][r]%q*C[m-1][r]%q*d%q)%=q;
            d=d*c%q;
        }
        (opp*=C[n][k]*fpow(2ll,(m-1)*(n-k),q)%q)%=q;
        (ans2+=opp)%=q;
    }
    (ans2+=n*fpow(2ll,(m-1)*(n-1),q)%q)%=q;
    // cout<<ans2<<endl;

    cout<<((ans1-ans2)%q+q)%q<<endl;

    return 0;
}