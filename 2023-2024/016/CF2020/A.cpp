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
int k;
int ans=0;

signed main(){

    read(t);
    while(t--){
        ans=0;
        read(n);read(k);
        if(k==1){
            cout<<n<<endl;
            continue;
        }
        while(n){
            if(n<k){
                ans+=n;
                break;
            }
            ans++;
            int op=1;
            for(;op*k<=n;op*=k);
            n=n-op;
        }
        cout<<ans<<endl;
    }

    return 0;
}