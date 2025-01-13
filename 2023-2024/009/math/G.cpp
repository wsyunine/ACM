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

int x,y,m,n,l;
//x+tm=y+tn (mod l)
//t(m-n)+kl=y-x

int exgcd(int &x,int &y,int a,int b){
    if(!b){x=1,y=0;return a;}
    int d=exgcd(y,x,b,a%b);
    y-=(a/b)*x;
    return d;
}

signed main(){

    read(x),read(y),read(m),read(n),read(l);
    int t,k;
    int a=m-n,b=y-x;
    if(a<0) a=-a,b=-b;
    int g=exgcd(t,k,a,l);
    if(b%g){
        cout<<"Impossible"<<endl;
    }else{
        cout<<((t*(b/g))%(l/g)+(l/g))%(l/g)<<endl;
    }

    return 0;
}