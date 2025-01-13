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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,sum=0;
int a[N];

int exgcd(int &x,int &y,int a,int b){
    if(b==0){x=1,y=0;return a;}
    int g=exgcd(y,x,b,a%b);
    y-=(a/b)*x;
    return g;
}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) read(a[i]),(sum+=a[i])%=m;
    int x,y;
    int g=exgcd(x,y,n,(n+1)*n/2);
    ((m-sum)%g)?sum+=((m-sum)/g+1)*g:sum=0;
    sum=sum%m;
    x=x+((-2*x)/(n*(n+1)))*((n+1)*n/2);
    if(x<0) x+=n*(n+1)/2;
    y=y-(y/n)*n;
    if(y<0) y+=

    cout<<sum<<endl;
    cout<<x<<" "<<y<<endl;

    return 0;
}