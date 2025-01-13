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

int n,m;
int x[N],d[N],ds=0,ans=0x3f3f3f3f3f3f3f3f;
vector<int> s[N];

signed main(){

    read(n),read(m);
    for(int i=1;i<=m;i++) read(x[i]),s[x[i]].push_back(i);

    for(int i=1;i<m;i++) d[i]=abs(x[i+1]-x[i]),ds+=d[i];

    ans=ds;
    for(int i=n;i>1;i--){
        for(auto j:s[i]){
            if(j>1) ds-=d[j-1],d[j-1]=n-d[j-1],ds+=d[j-1];
            if(j<m) ds-=d[j],d[j]=n-d[j],ds+=d[j];
        }
        ans=min(ans,ds);
    }

    cout<<ans<<endl;

    return 0;
}