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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
ll n;
int a[N],b[N];

int main(){

    read(t);
    while(t--){
        read(n);
        ll sa=0,sb=0;
        ll mina=1e9+1,minb=1e9+1;
        for(int i=1;i<=n;i++) read(a[i]),sa+=a[i],mina=min(mina,(ll)a[i]);
        for(int i=1;i<=n;i++) read(b[i]),sb+=b[i],minb=min(minb,(ll)b[i]);

        cout<<min(sa+minb*n,sb+mina*n)<<endl;
    }

    return 0;
}