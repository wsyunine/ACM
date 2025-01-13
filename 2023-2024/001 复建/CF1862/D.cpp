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


signed main(){

    int P;
    cin>>P;
    while(P--){
        int n;
        cin>>n;
        int l=2,r=2648956421;
        while(l<r){
            int mid=(l+r+1)>>1;
            if((mid-1)*mid/2>n) r=mid-1;
            else l=mid;
        }
        if(l*(l-1)/2==n) cout<<l<<endl;
        else cout<<l+(n-(l*(l-1)/2))<<endl;
    }

    return 0;
}