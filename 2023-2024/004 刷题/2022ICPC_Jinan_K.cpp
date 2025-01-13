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
#define N 600010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,a[N],num[N];

int main(){

    read(t);
    while(t--){
        read(n);
        int ans=0;
        for(int i=1;i<=n;i++) read(a[i]),num[i]=-1;
        num[n+1]=-1;

        for(int i=1;i<=n;i++){
            if(num[a[i]+1]==-1) num[a[i]]=++ans;
            else num[a[i]]=num[a[i]+1];
        }

        cout<<ans<<endl;
    }

    return 0;
}