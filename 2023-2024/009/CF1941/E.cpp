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
#define ll long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int t;
int d,k;
int mapp[101][200010];
ll f[101][200010],sum[100010];
ll ans=0;

signed main(){

    read(t);
    while(t--){
        read(n),read(m);ans=0x3f3f3f3f3f3f3f3f;
        read(k),read(d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) read(mapp[i][j]);
        }

        for(int i=1;i<=n;i++){
            vector<int> q(m+1);
            int front=0,tail=-1;
            for(int j=1;j<=m;j++){
                while(front<=tail&&j-q[front]>d+1) front++;
                if(j==1) f[i][j]=1;
                else{
                    f[i][j]=f[i][q[front]]+mapp[i][j]+1;
                }
                while(front<=tail&&f[i][j]<f[i][q[tail]]) tail--;
                q[++tail]=j;
            }
            // for(int j=1;j<=m;j++) cout<<f[i][j]<<" ";
            // cout<<endl;
        }

        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i][m];

        for(int i=1;i<=n-k+1;i++){
            ans=min(ans,sum[i+k-1]-sum[i-1]);
        } 

        cout<<ans<<endl;
    }

    return 0;
}