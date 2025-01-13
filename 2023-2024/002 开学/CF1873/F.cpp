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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,k;
int s[N];
int h[N];

signed main(){

    read(t);
    while(t--){
        read(n),read(k);

        int ans=0;

        s[0]=0;

        for(int i=1;i<=n;i++){
            int a;
            read(a);
            s[i]=s[i-1]+a;
        }

        for(int i=1;i<=n;i++) read(h[i]);
        h[n+1]=1e9+1;

        int i=1,j=0;
        while(s[i]-s[j]>k) j++;
        ans=max(ans,i-j);
        while(i<n){
            if(h[i]%h[i+1]==0){
                i++;
            }else{
                i++;
                j=i-1;
            }
            while(s[i]-s[j]>k) j++;
            ans=max(ans,i-j);
            // cout<<i<<" "<<j<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}