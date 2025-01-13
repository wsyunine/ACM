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

int fmul(int a,int b,int p){
    int res=0;a%=p;
    for(;b;b>>=1,a=(a+a)%p) if(b&1) (res+=a)%=p;
    return res;
}

signed main(){

    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);

    // for(int i=1;i<=n;i++) cin>>b[i]>>a[i];

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int lcm=1,ans=0,x,y;
    for(int i=1;i<=n;i++) lcm*=b[i];
    for(int i=1;i<=n;i++){
        int m=lcm/b[i];
        exgcd(m,b[i],x,y);
        (a[i]+=lcm)%=lcm;
        ans=(ans+fmul(fmul(x,m,lcm),a[i],lcm))%lcm;
    }

    cout<<(ans%lcm+lcm)%lcm<<endl;

    return 0;
}