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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int t;
int m;
int p;

signed main(){

    read(t);
    while(t--){
        read(p),read(m);

        // for(int i=0;i<=100;i++){
        //     cout<<((i*p+1)^(p-1))<<" ";
        // }

        // int l=0,r=(m-1)/p+10;
        // while(l<r){
        //     int mid=(l+r+1)>>1;
        //     if(((mid*p+1)^(p-1))<=m) l=mid;
        //     else r=mid-1;
        // }
        // printf("%lld\n",l+1);

        int l=m/p-1;
        int r=(m-2-1)/p+2;
        if((r-1)*p+2==m) r++;

        int ans=l+1;
        for(int i=l+1;i<r;i++){
            if(((i*p+1)^(p-1))<=m) ans++;
        }

        cout<<ans<<endl;

    }

    return 0;
}