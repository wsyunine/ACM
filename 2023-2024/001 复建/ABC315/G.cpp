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

int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}

int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1;y=0;return a;}
    int g=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

signed main(){

    int n,a,b,c,x,cnt=0;
    cin>>n>>a>>b>>c>>x;

    int q=gcd(b,c);
    for(int i=1;i<=n&&i*a<x;i++){
        int p=x-a*i;
        if(p%q) continue;
        int u,v,x,y;
        u=b/q,v=c/q,p/=q;
        exgcd(u,v,x,y);
        if(x<=0&&y<=0) 
    }

    cout<<cnt<<endl;

    return 0;
}