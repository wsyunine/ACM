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

int t;
int n;
int a[N];

signed main(){

    read(t);
    while(t--){
        read(n);
        int ans=0,mx=0;
        for(int i=1;i<=n;i++) read(a[i]);
        
        mx=a[n];
        for(int i=n-1;i>=1;i--){
            // while(a[i]>mx){
            //     int x=(a[i]%2)?(a[i]/2+1):(a[i]/2);
            //     x=min(x,mx);
            //     // cout<<i<<" "<<x<<endl;
            //     mx=x;
            //     a[i]-=x;
            //     ans++;
            // }
            if(a[i]<=mx){
                mx=a[i];
                continue;
            }
            if(a[i]%mx==0){
                ans+=((a[i]/mx)-1);
                continue;
            }
            int y=a[i]/mx;
            ans+=y;
            mx=a[i]/(y+1);
            // cout<<mx<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}