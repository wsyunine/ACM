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
#define N 2000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,c;
int s[N];
int sumj,sumo;
int ans=0;

signed main(){

    read(t);
    while(t--){
        read(n);read(c);
        sumj=0,sumo=0;ans=0;ans=(c+2)*(c+1)/2;
        for(int i=1;i<=n;i++){
            read(s[i]);
            (s[i]&1)?sumj++:sumo++;
            ans-=((s[i]>>1)+1);
            ans-=(c-s[i]+1);
        }

        ans+=(((sumj)*(sumj-1)/2)+sumj);
        ans+=(((sumo)*(sumo-1)/2)+sumo);

        printf("%lld\n",ans);
    }

    return 0;
}