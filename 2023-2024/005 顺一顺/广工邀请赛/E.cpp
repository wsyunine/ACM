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
int s[N],a[N],ans=0;
int pre[N];

int main(){

    memset(pre,-1,sizeof pre);
    read(n);
    s[0]=0;
    pre[101000]=0;
    for(int i=1;i<=n;i++){
        read(a[i]);
        if(a[i]) s[i]=s[i-1]+1;
        else s[i]=s[i-1]-1;
        if(pre[s[i]+101000]!=-1) ans=max(ans,i-pre[s[i]+101000]);
        else pre[s[i]+101000]=i;
    }
    
    cout<<ans<<endl;

    return 0;
}