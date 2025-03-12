#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n;
int a[N];
int prime[N],cnt=0,mindiv[N],sum[N];
bool pri[N];

void get_primes(int x){
    for(int i=2;i<=x;i++){
        if(!mindiv[i]) prime[++cnt]=i,pri[i]=1,mindiv[i]=i;
        for(int j=1;j<=cnt;j++){
            if(prime[j]>mindiv[i]||prime[j]*i>x) break;
            mindiv[prime[j]*i]=prime[j];
        }
    }
}

void solve() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=0;i<=n;i++) sum[i]=0;
    for(int i=1;i<=n;i++){
        if(pri[a[i]]) sum[a[i]]++;
    }

    int opt=0,res=0;
    for(int i=1;i<=n;i++){
        if(!sum[i]) continue;
        res+=sum[i]*opt;
        opt+=sum[i];
    }

    // for(int i=1;i<=n;i++) sum[i]=0;
    for(int i=1;i<=n;i++){
        if(pri[a[i]]) continue;
        sum[a[i]]++;
    }

    // cout<<res<<endl;

    for(int i=2;i<=n;i++){
        if(!sum[i]) continue;
        if(pri[i]) continue;
        int op=0,num1=0,num2=0;
        for(int j=1;j<=cnt;j++){
            if(i%prime[j]==0){
                if(pri[i/prime[j]]==1){
                    num1=prime[j];
                    num2=i/prime[j];
                    op=1;
                }else op=0;
                break;
            }
        }
        if(op){
            res+=sum[i]*(sum[i]-1)/2;
            res+=sum[i];
            res+=sum[i]*sum[num1];
            if(num1!=num2) res+=sum[i]*sum[num2];
        }
    }

    cout<<res<<endl;

}

signed main() {
    get_primes(200000);
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}