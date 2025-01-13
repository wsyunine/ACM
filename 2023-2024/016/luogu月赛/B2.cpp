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

int t;

ll a,b,c,d;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

bool is_prime(ll x){
    for(ll i=2;i<=x/i;i++){
        if(x%i==0) return 0;
    }
    return 1;
}

int main(){

    read(t);
    while(t--){
        cout<<"? 100000000000000001"<<endl;
        fflush(stdout);
        a=100000000000000001;
        ll op1,op2;
        cin>>op1;
        ll res=a-op1;
        cout<<"? "<<res-1<<endl;
        fflush(stdout);
        cin>>op2;
        

        cout<<"! "<<op2+1<<endl;
        fflush(stdout);
    }

    return 0;
}