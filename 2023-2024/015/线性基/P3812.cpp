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
int a[N];
int b[100];

void ins(int x){
    for(int i=63;i>=0;i--){
        if((x&(1ll<<i))==0) continue;
        if(!b[i]){b[i]=x;return;}
        else x^=b[i];
    }
}

int query(){
    int res=0;
    for(int i=63;i>=0;i--){
        if(!b[i]) continue;
        if((res^b[i])>res) res=res^b[i];
    }
    return res;
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]),ins(a[i]);

    cout<<query()<<endl;

    return 0;
}