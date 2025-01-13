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

int n;
int m;

int exgcd(int &x,int &y,int a,int b){
    if(!b){x=1,y=0;return a;}
    int d=exgcd(y,x,b,a%b);
    y-=(a/b)*x;
    return d;
}

int fpow(int a,int b,int p){
    int res=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res;
}

int crt(int n,int *a,int *b){
    int lcm=1;
    __int128 ans=0,x,y;
    for(int i=1;i<=n;i++) lcm*=b[i];
    for(int i=1;i<=n;i++){
        int m=lcm/b[i];
        x=fpow(m,b[i]-2,b[i]);
        ans=(ans+x*m*a[i])%lcm;
        // cout<<ans<<" "<<lcm<<endl;
    }
    return (ans+lcm)%lcm;
}

signed main(){

    int t;
    read(t);
    while(t--){
        int opa[3],opb[3];
        cout<<"? 399999949"<<endl;
        opb[1]=399999949;
        fflush(stdout);
        cin>>opa[1];
        cout<<"? 399999959"<<endl;
        opb[2]=399999959;
        fflush(stdout);
        cin>>opa[2];

        cout<<"! "<<crt(2,opa,opb)<<endl;
        fflush(stdout);
    }

    return 0;
}