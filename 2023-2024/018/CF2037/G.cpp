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
#include<unordered_map>
using namespace std;
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const long long Mod=998244353;

int t;
int n;
long long a[N];

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    
    int m=*max_element(a+1,a+1+n);
    vector<vector<int>> ds(m+1);
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j+=i){
            ds[j].push_back(i);
        }
    }

    vector<long long> c(m+1,1);
    c[1]=0;
    for(int i=1;i<=m;i++){
        for(int j=2*i;j<=m;j+=i){
            c[j]-=c[i];
        }
    }

    vector<long long> g(m+1);
    vector<long long> f(n+1);

    for(int i=1;i<=n;i++){
        for(auto d:ds[a[i]]){
            (f[i]=f[i]+g[d]*c[d]+Mod)%=Mod;
        }
        if(i==1) f[i]+=1;
        for(auto d:ds[a[i]]){
            (g[d]+=f[i])%=Mod;
        }
    }

    cout<<f[n]<<endl;
    

    return 0;
}