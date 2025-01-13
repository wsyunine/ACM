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
#define INF 1e18
#define llo long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,cl,cr;
int a[N];
llo f[30][N],g[30][N],s[N];
int lg[N]={-1};
llo ans[N];

void init(){
    memset(g,INF,sizeof(g));
    memset(f,-INF,sizeof(f));
    memset(ans,-INF,sizeof(ans));
    for(int i=0;i<=n;i++) g[0][i]=f[0][i]=s[i];
    for(int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
    for(int i=1;i<=lg[n];i++){
        for(int j=0;j+(1<<i)-1<=n;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
            g[i][j]=min(g[i-1][j],g[i-1][j+(1<<(i-1))]);
        }
    }
}

llo query1(int l,int r){
    if(l>r) return -0x3f3f3f3f; 
    int len=lg[r-l+1];
    return max(f[len][l],f[len][r-(1<<len)+1]);
}

llo query2(int l,int r){
    if(l>r) return 0x3f3f3f3f;
    int len=lg[r-l+1];
    return min(g[len][l],g[len][r-(1<<len)+1]);
}

void solve(int l,int r){
    if(r-l+1<cl) return;
    if(l==r){
        ans[l]=s[l];
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    int ll,rr;
    llo pre=-0x3f3f3f3f;
    for(int i=l;i<=mid;i++){
        ll=max(mid+1,i+cl-1);
        rr=min(r,i+cr-1);
        pre=max(pre,query1(ll,rr)-s[i-1]);
        ans[i]=max(ans[i],pre);
    }
    pre=-0x3f3f3f3f;
    for(int i=r;i>=mid+1;i--){
        ll=max(l,i-cr+1);
        rr=min(mid,i-cl+1);
        pre=max(pre,s[i]-query2(ll-1,rr-1));
        ans[i]=max(ans[i],pre);
    }
}

int main(){

    // freopen("data9.in","r",stdin);
    // freopen("data9.out","w",stdout);

    read(n),read(cl),read(cr);

    s[0]=0;
    for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];

    init();

    solve(1,n);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}