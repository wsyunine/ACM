#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n;
int e[N],ne[N],h[N],idx;
int dp1[N],dp2[N],d[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int x,int fa){
    dp1[x]=d[x];
    dp2[x]=0;
    int mx1=0,mx2=0;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
        dp1[x]=max(dp1[x],dp1[j]+d[x]-2);
        if(dp1[j]>mx1) mx2=mx1,mx1=dp1[j];
        else if(dp1[j]>mx2) mx2=dp1[j];
    }
    if(mx1&&mx2){
        dp2[x]=mx1+mx2+d[x]-4;
    }
}

void solve() {
    read(n);
    for(int i=1;i<=n;i++) d[i]=0,h[i]=-1;
    for(int i=1;i<n;i++){
        int a,b;
        read(a),read(b);
        add(a,b);
        add(b,a);
        d[a]++,d[b]++;
    }

    dfs(1,1);

    int res=1;
    for(int i=1;i<=n;i++){
        res=max(res,dp1[i]);
        res=max(res,dp2[i]);
    }

    cout<<res<<endl;
}

int main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}