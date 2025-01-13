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

int mindiv[N],pri[N],cnt=0;
void primes(int n){
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=i,mindiv[i]=i;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
        }
    }
}

int n;
int k;
int t;
int a[N];

bool check(int x){
    for(int i=1;i<=n;i++)
}

signed main(){

    primes(200000);

    read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++) read(a[i]);

        int l=-200000000,r=200000000;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
    }

    return 0;
}