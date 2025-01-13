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

int t;
int n,k;
int v[N];

int check(int x){
    int rk=0;
    for(int i=1,j=n;i<j;i++){
        while(v[i]+v[j]>=x) j--;
        rk+=(j-i);
    }
    return rk+1;
}

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(v[i]);
        sort(v+1,v+1+n);
        read(k);

        int l=2,r=v[n]+v[n-1];
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)<=k) l=mid;
            else r=mid-1; 
        }

        cout<<l<<endl;

    }

    return 0;
}