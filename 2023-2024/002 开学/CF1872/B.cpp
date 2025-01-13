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

int main(){

    int t;
    read(t);
    while(t--){
        int n,ans=0x3f3f3f3f;
        read(n);
        vector<int> d(n+1),s(n+1);
        for(int i=1;i<=n;i++) read(d[i]),read(s[i]);

        for(int i=1;i<=n;i++){
            ans=min(ans,d[i]+(s[i]+1)/2-1);
        }

        cout<<ans<<endl;
    }

    return 0;
}