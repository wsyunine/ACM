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
int a,b,c,ans=0;

signed main(){

    read(n);
    for(int i=1;i<=n;i++){
        read(a),read(b),read(c);ans=0x3f3f3f3f3f3f3f3f;

        for(int j=0,k=1;j<=32;j++,k*=2){
            if(k>=c){
                ans=min(ans,j*a+b);
                break;
            }
            ans=min(ans,j*a+(int)ceil(1.0*c/(1.0*k))*b);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}