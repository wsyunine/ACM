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
int p;
int ans=0;
int C[5050][5050];

void init(){
    C[1][0]=C[1][1]=1;
    for(int i=2;i<=5000;i++){
        C[i][0]=1;C[i][1]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
        }
    }
}

int fpow(int a,int b,int p){
    int res=1%p;a%=p;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res%p;
}

signed main(){

    read(n),read(m),read(p);
    if(p==1){
        cout<<0<<endl;
        return 0;
    }
    init();
    int op=n;

    for(int i=1;i<=n;i++){
        int b=(fpow(2ll,i,p)-1ll+p)%p;
        b=fpow(b,m-1ll,p);
        (ans+=C[n][i]*b%p*fpow(2ll,(m-1)*(n-i),p)%p)%=p;
    }
    cout<<ans<<endl;

    return 0;
}