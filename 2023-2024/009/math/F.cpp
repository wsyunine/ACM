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

int t,n;

int pri[N],phi[N],mindiv[N],cnt=0;
void get_phi(int n){
    phi[1]=0;
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=mindiv[i]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++){
            if(mindiv[i]<pri[j]||i*pri[j]>n) break;
            mindiv[i*pri[j]]=pri[j];
            phi[i*pri[j]]=phi[i]*((i%pri[j])?(pri[j]-1):pri[j]);
        }
    }
}

int main(){

    get_phi(1000);
    for(int i=2;i<=1000;i++) phi[i]+=phi[i-1];

    int t;
    read(t);
    for(int i=1;i<=t;i++){
        read(n);
        cout<<i<<" "<<n<<" "<<(phi[n]+1)*2+1<<endl;
    }

    return 0;
}