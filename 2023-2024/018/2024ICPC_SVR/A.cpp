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
int a[N];
int b[N];
int c[N];

int main(){

    read(n),read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);

    for(int i=n;i>=1;i--){
        c[i]=min(a[i]/b[i],k);
        k-=min(a[i]/b[i],k);
        if(!k) break;
    }

    if(k){
        for(int i=1;i<=n;i++) printf("0 ");
        cout<<endl;
    }else{
        for(int i=1;i<=n;i++) printf("%d ",c[i]);
        cout<<endl;
    }

    return 0;
}