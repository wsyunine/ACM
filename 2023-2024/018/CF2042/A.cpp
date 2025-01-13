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

int t;
int n,k;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++) read(a[i]);

        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);

        int tmp=0,mn=1e9+7;
        for(int i=1;i<=n;i++){
            tmp+=a[i];
            if(tmp>k) break;
            mn=min(mn,k-tmp);
        }

        cout<<mn<<endl;
    }

    return 0;
}