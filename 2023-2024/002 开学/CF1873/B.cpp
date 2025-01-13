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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;

int main(){

    read(t);
    while(t--){
        int n,ti=1,ans=0,n0=0;
        read(n);
        vector<int> s(n+1);
        for(int i=1;i<=n;i++) read(s[i]),n0+=(s[i]==0),ti*=((s[i]==0)?1:s[i]);

        if(n0==1){
            cout<<ti<<endl;
            continue;
        }else if(n0>1){
            cout<<0<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            ans=max(ans,ti/s[i]*(s[i]+1));
        }

        cout<<ans<<endl;
    }

    return 0;
}