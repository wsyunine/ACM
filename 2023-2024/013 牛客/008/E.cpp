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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,ans=0;
int w[N];

int getw(int x){
    if(x<=1000000) return w[x];
    else return w[x/1000000]+w[x%1000000];
}

signed main(){

    for(int i=1;i<=1000000;i++) w[i]=w[i/10]+i%10;

    read(t);
    while(t--){
        read(n);ans=0;
        int op=min(108ll,n-1);
        for(int i=1;i*i<=n;i++){
            int j=(n-op)%i==0?n-op:((n-op)/i+1)*i;
            for(;j<=n-1;j+=i){
                if(i!=n-j&&n-j==getw(i)) ans++;
                if(j/i!=i&&n-j==getw(j/i)&&j/i!=n-j) ans++;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}