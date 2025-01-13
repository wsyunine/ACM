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

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

signed main(){

    int t;
    read(t);
    while(t--){
        int n,x,y;
        read(n),read(x),read(y);
        
        int lcm=x*y/gcd(x,y);

        int a=n/x-n/lcm,b=n/y-n/lcm;

        b=(1+b)*b/2;
        a=a*(2*n-a+1)/2;

        cout<<(a-b)<<endl;
    }

    return 0;
}