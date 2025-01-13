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

int n;
int t;
int k;
long long a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+1+n);

        int p1=1;
        for(int i=1;i<=n;i++){
            while(p1<i&&a[p1]<=a[i]/2) p1++;
            if(p1>1&&a[p1]+a[p1-1]>a[i]) ans=min(ans,(n-i)+(max(p1-2,0)));
            else ans=min(ans,(n-i)+(max(p1-1,0)));
            //cout<<(n-i)+(max(p1-2,0))<<endl;
        }

        cout<<ans<<endl;

    }

    return 0;
}