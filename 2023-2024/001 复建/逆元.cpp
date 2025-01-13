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

int main(){

    long long n,p;
    read(n);read(p);
    vector<long long> inv(n+1);
    inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]= (long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++) printf("%d\n",inv[i]);

    return 0;
}