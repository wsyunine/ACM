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

int n;
int a[N],mx1=0,mx2=0;

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++){
        if(a[i]>mx1) mx2=mx1,mx1=a[i];
        else if(a[i]>mx2) mx2=a[i];
    }

    cout<<mx1+mx2<<endl;

    return 0;
}