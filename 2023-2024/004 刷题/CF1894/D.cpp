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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t,n,m;
int a[N],b[N],c[N];
map<int,int> cnt;

int main(){

    read(t);
    while(t--){
        read(n),read(m);
        
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=m;i++) read(b[i]);

        sort(b+1,b+1+m,greater<int>());

        merge(a+1,a+1+n,b+1,b+1+m,c+1,greater<int>());

        for(int i=1;i<=m+n;i++) cout<<c[i]<<" ";
        cout<<endl;
    }

    return 0;
}