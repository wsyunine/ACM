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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],b[N];
int t,ans=0;
int f[N][20],logn[N]={-1};

int gcd(int a,int b){
    if(a<b) swap(a,b);
    return b==0?a:gcd(b,a%b);
}

void init(){
    for(int i=1;i<n;i++) f[i][0]=b[i],logn[i]=logn[i/2]+1;
    for(int j=1;j<=logn[n-1];j++){
        for(int i=1;i+(1<<j)-1<n;i++){
            f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int len=logn[r-l+1];
    return gcd(f[l][len],f[r-(1<<len)+1][len]);
}

signed main(){

    read(t);
    while(t--){
        read(n);ans=0;
        for(int i=1;i<=n;i++) read(a[i]);
        if(n==2){
            if(abs(a[1]-a[2])==1) cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }

        for(int i=1;i<n;i++){
            b[i]=abs(a[i+1]-a[i]);
        }

        init();

        // for(int i=1;i<n;i++) cout<<b[i]<<endl;

        for(int i=1,j=1;i<n;i++){
            while(j<i&&query(j,i)==1) j++;
            // cout<<i-j+1<<endl;
            if(i!=j||b[i]!=1) ans=max(ans,i-j+1);
        }

        cout<<ans+1<<endl;
    }

    return 0;
}