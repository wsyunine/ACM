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

int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1,y=0;return a;}
    int gcd=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return gcd;
}

signed main(){

    int a,b;
    cin>>a>>b;
    int x,y;
    int gcd=exgcd(a,b,x,y);
    x=(x%(b/gcd)+(b/gcd))%(b/gcd);
    cout<<x<<endl;

    return 0;
}