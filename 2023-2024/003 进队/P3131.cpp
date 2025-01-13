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
int a[N],s[N],p[N],ans=0;

int main(){

    read(n);
    s[0]=0;
    for(int i=1;i<=n;i++) p[i]=-1,read(a[i]),s[i]=(s[i-1]+a[i])%7;

    for(int i=1;i<=n;i++){
        if(p[s[i]]==-1) p[s[i]]=i;
        ans=max(ans,i-p[s[i]]);
    }

    cout<<ans<<endl;

    return 0;
}