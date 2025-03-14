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
int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a) if(b&1) res=res*a;
    return res;
}

signed main(){

    read(n);
    if(n%2){
        cout<<fpow(2,n-1)<<endl;
    }else{
        cout<<fpow(2,n/2-1)*3<<endl;
    }

    return 0;
}