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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k,p;
int t;
ll f[405][405][405];
ll sum[405][405][405];

int main(){

    read(t);
    while(t--){
        read(n);read(k),read(p);

        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(j<=i) f[2][i][j]=1;
                else f[2][i][j]=0;
                sum[2][i][j]=sum[2][i][j-1]+f[2][i][j];
            }
        }

        for(int i=3;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int u=0;u<=k;u++){
                    if(u-j<=0) f[i][j][u]=sum[i-1][u][k]%p;
                    else f[i][j][u]=(sum[i-1][u][k]-sum[i-1][u][u-j-1]+p)%p;
                    sum[i][j][u]=(sum[i][j][u-1]+f[i][j][u])%p;
                    // cout<<f[i][j][u]<<" ";
                }
                // cout<<endl;
            }
            // cout<<endl;
        }

        ll res=0;
        for(int i=0;i<=k;i++){
            for(int j=i;j<=k;j++){
                (res+=f[n][i][j])%=p;
            }
        }

        cout<<res<<endl;
    }

    return 0;
}