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
int a[N],cnt[N];

int main(){

    read(t);
    while(t--){
        read(n),read(k);
        for(int i=1;i<=n;i++) cnt[i]=0,read(a[i]);

        int pos=n;
        while(cnt[pos]<1&&a[pos]<=n&&k){
            k--;
            cnt[pos]++;
            pos=(pos+2*n-a[pos]-1)%n+1;
        }
        if(k==0){cout<<"Yes"<<endl;continue;}
        if(cnt[pos]==1){cout<<"Yes"<<endl;continue;}
        cout<<"No"<<endl;
    }

    return 0;
}