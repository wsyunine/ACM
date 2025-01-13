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
#define N 500010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
ll pre[N];
string s;
ll mod=998244353;

ll fmul(ll a,ll b){
    ll res=0;a%=mod;
    for(;b;b>>=1,a=(a+a)%mod) if(b&1) res=(res+a)%mod;
    return res%mod;
}

int main(){

    pre[1]=1,pre[2]=2;
    pre[0]=1;
    for(int i=3;i<=200000;i++){
        pre[i]=fmul(pre[i-1],i);
    }

    read(t);
    while(t--){
        cin>>s;
        int len=s.size();
        ll ans1=0,ans2=1;
        for(int i=1,op=0,sum=1;i<=len;i++,sum++){
            if(s[i]!=s[op]){
                ans1+=(sum-1);
                ans2=fmul(ans2,sum);
                sum=0;
                op=i;
            }
        }

        cout<<ans1<<" "<<ans2*pre[ans1]%mod<<endl;
    }

    return 0;
}