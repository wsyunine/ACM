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
ll m;
int t;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        ll ans=0;

        if(m%n!=0){
            cout<<-1<<endl;
            continue;
        }else if(n==m){
            cout<<0<<endl;
            continue;
        }
        
        ll pos=m/n;
        while(gcd(pos,n)!=1){
            ans++;
            n=n*gcd(pos,n);
            pos=m/n;
        }

        if(m!=n) cout<<-1<<endl;
        else cout<<ans<<endl;

    }

    return 0;
}