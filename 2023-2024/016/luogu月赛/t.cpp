#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define N 1000010
#define int long long
#define re register
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],b[N];

int exgcd(int a,int b,int &x,int &y){
    if(!b){x=1,y=0;return a;}
    int d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

int CRT(){
    int res=0,x,y,lcm=1;
    for(int i=1;i<=n;i++) lcm*=a[i];
    for(int i=1;i<=n;i++){
        int m=lcm/a[i];
        exgcd(m,a[i],x,y);
        res=(res+x*m*b[i])%lcm;
    }
    return (res+lcm)%lcm;
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
    printf("%lld\n",CRT());
    
    return 0;
}