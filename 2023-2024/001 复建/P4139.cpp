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
#define N 10000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int fpow(int a,int b,int p){
    int res=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res%p;
}

bool notp[N];
int phi[N];
int pri[1000010],cnt=0;

void prime(int x){
    notp[1]=1;
    for(int i=2;i<=x;i++){
        if(!notp[i]) pri[++cnt]=i,phi[i]=i-1;
        for(int j=1,t;j<=cnt,(t=i*pri[j])<=x;j++){
            notp[t]=1;
            phi[t]=phi[i]*((i%pri[j])?(pri[j]-1):pri[j]);
            if(i%pri[j]==0) break;
        }
    }
}

int solve(int p){
    if(p==1) return 0;
    int ans=fpow(2,solve(phi[p])+phi[p],p);
    return ans;
}

signed main(){

    prime(N-10);

    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<solve(a)<<endl;
    }

    return 0;
}