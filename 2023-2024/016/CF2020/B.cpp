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

int t;
int n;

signed main(){

    read(t);
    while(t--){
        read(n);
        int l=1,r=2e18;
        while(l<r){
            int mid=(l+r)>>1;
            if(mid-(int)sqrtl(mid)>=n) r=mid;
            else l=mid+1; 
        }
        cout<<l<<endl;
    }

    return 0;
}