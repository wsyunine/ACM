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
#define N 1000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,t;

ll mindiv[N],pri[N],phi[N],cnt=0;
void getphi(int n){
    phi[1]=0;
    for(ll i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=mindiv[i]=i,phi[i]=i-1;
        for(ll j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
            phi[pri[j]*i]=phi[i]*((i%pri[j])?(pri[j]-1):pri[j]);
        }
    }
}

int main(){

    getphi(1000000);
    for(int i=2;i<=1000000;i++) phi[i]+=phi[i-1];

    while(cin>>n){
        if(!n) break;
        cout<<phi[n]<<endl;
    }

    return 0;
}