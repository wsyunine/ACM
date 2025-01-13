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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int q[N],r[N];
int qq;

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(q[i]),read(r[i]);

    read(qq);
    while(qq--){
        int t,d;
        read(t),read(d);

        if(d%q[t]==r[t]){
            cout<<d<<endl;
        }else if(d%q[t]<r[t]){
            cout<<d+r[t]-(d%q[t])<<endl;
        }else{
            cout<<d+q[t]-((d%q[t])-r[t])<<endl;
        }
    }

    return 0;
}