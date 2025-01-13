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

ll n;
int t;
ll m;
int pri[N],cnt,mindiv[400000010];
ll num[N];

void primes(int x){
    mindiv[1]=mindiv[0]=1;
    for(int i=2;i<=x;i++){
        if(!mindiv[i]) cout<<i<<endl,mindiv[i]=i,pri[++cnt]=i;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||i*pri[j]>x) break;
            mindiv[i*pri[j]]=pri[j];
        }
    }
}

int main(){

    primes(400000000);

    read(t);
    while(t--){
        ll ans=0;
        read(n),read(m);

        if(m%n!=0){
            cout<<-1<<endl;
            continue;
        }else if(n==m){
            cout<<0<<endl;
            continue;
        }
        ll op=m/n;
        ll op1=n;

        for(int i=1;pri[i]<=n&&i<=cnt;i++){
            while(n%pri[i]==0) num[i]++,n/=pri[i];
            //cout<<pri[i]<<" "<<num[i]<<endl;
        }
        
        int id=0;
        for(int i=1;pri[i]<=op&&i<=cnt;i++){
            int s=0;
            while(op%pri[i]==0) s++,op/=pri[i];
            if(s){
                if(num[i]==0) id=1;
                else{
                    ll x=(s-1)/num[i]+2;
                    //cout<<log2(x)<<endl;
                    ans=max((ll)ceil(log2(x)),ans);
                }
            }
        }

        if(id) cout<<-1<<endl;
        else cout<<ans<<endl;

        n=op1;

        for(int i=1;pri[i]<=n&&i<=cnt;i++){
            num[i]=0;
        }

    }

    return 0;
}