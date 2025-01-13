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
#define N 300010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N];
int s[N][31];
int ans=0;
int mod=998244353;

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            s[i][j]=s[i-1][j]^(a[i]>>j&1);
        }
    }

    for(int i=0;i<=30;i++){
        int tmp=0,len0=1,cnt0=1,cnt1=0,len1=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]){
                (tmp+=len0)%=mod;
                cnt1++;
            }else{
                (tmp+=len1)%=mod;
                cnt0++;
            }
            (len0+=cnt0)%=mod;
            (len1+=cnt1)%=mod;
        }
        (ans+=tmp*(1<<i)%mod)%=mod;
    }

    cout<<ans<<endl;

    return 0;
}

/*
 
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
 
  
 
  1. Think TWICE, Code ONCE!
 
  Are there any counterexamples to your algo?
 
    
 
  2. Be careful about the BOUNDARIES!
 
  N=1? P=1? Something about 0?
 
    
 
  3. Do not make STUPID MISTAKES!
 
  Time complexity? Memory usage? Precision error?
 
*/
