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
#define ll long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

ll n;
ll k;
ll m;
ll ans=0;

int main(){

    read(n),read(m);read(k);
    for(int i=1;i<=k;i++){
        ll a,b;
        read(a),read(b);
        if(b>=a) ans++;
    }
    cout<<ans<<endl;

    return 0;
}