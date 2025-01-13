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

int n;
int a[N],pre[N],ans=0;

int t[N];

void add(int x,int y){
    for(;x<=100000;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    for(int i=1;i<=n;i++){
        pre[i]=query(a[i]-1);
        add(a[i],1);
    }
    
    memset(t,0,sizeof t);

    for(int i=n;i>=1;i--){
        ans+=pre[i]*(query(100000)-query(a[i]));
        add(a[i],1);
    }

    cout<<ans<<endl;

    return 0;
}