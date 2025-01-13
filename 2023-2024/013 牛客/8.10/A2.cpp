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
#define N 10010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

typedef long long LL;

LL mindiv[N],pri[N],cnt=0;
LL dp[N];
void primes(int n){
    for(int i=2;i<=n;i++){
        if(!mindiv[i]) pri[++cnt]=i,mindiv[i]=i;
        for(int j=1;j<=cnt;j++){
            if(pri[j]>mindiv[i]||pri[j]*i>n) break;
            mindiv[pri[j]*i]=pri[j];
        }
    }
}

int main()
{
    LL a, b;
    cin >> a >> b;
    primes(10000);
    int cn = cnt;
    for (int i = 1; i <= cnt; i++)
        if (b % pri[i] == 0) {
            pri[i] = 0x3f3f3f3f;
            cn--;
        }
    pri[++cnt] = 1;
    cn ++;
    sort(pri + 1, pri + 1 + cnt);
    //for (int i = 1; i <= cn; i++)
    //    cout << pri[i] << " ";
    for (int i = 1; i <= cn; i++)
    {
        for (int j = pri[i]; j <= 10000; j++)
            dp[j] = max(dp[j], dp[j - pri[i]] + 1);
    }
    
    return 0;
}