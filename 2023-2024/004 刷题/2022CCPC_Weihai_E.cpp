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
int a[N],sl=0,ans=0;

int main(){

    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    if(a[n-1]-a[n]<=0){
        cout<<"Python will never be faster than C++"<<endl;
        return 0;
    }
    k=a[n]-k;
    ans=n+k/(a[n-1]-a[n])+1;
    cout<<"Python 3."<<ans<<" will be faster than C++"<<endl;

    return 0;
}