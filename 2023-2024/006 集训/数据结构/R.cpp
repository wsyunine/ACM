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

int n,k;
int d[N];
int c[N];
int s[N];
int w[N];

int main(){

    read(n),read(k);
    for(int i=2;i<=n;i++) read(d[i]);
    for(int i=1;i<=n;i++) read(c[i]);
    for(int i=1;i<=n;i++) read(s[i]);
    for(int i=1;i<=n;i++) read(w[i]);

    for(int i=1;i<=n;i++){
        
    }

    return 0;
}