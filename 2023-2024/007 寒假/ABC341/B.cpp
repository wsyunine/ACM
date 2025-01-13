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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int a[N],s[N],t[N];

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<n;i++) read(s[i]),read(t[i]);

    int res;
    for(int i=1;i<n;i++){
        a[i+1]+=(a[i]/s[i])*t[i];
    }

    cout<<a[n]<<endl;

    return 0;
}