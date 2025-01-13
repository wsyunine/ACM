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
#define N 200010
#define ll long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int e[N],idx,ne[N],h[N];
int n;
pair<ll,ll> tr[N],dp[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first*b.second>a.second*b.first;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

pair<ll,ll> pluss(pair<ll,ll> a,pair<ll,ll> b){
    ll x=a.first*b.second+a.second*b.first,y=a.second*b.second;
    ll g=gcd(x,y);
    return {x/g,y/g};
}

void dfs(int x,int fa){
    pair<ll,ll> mx={-1,-1};
    dp[x]=tr[x];
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,x);
        if(mx.first==-1) mx=dp[j];
        else if(cmp(dp[j],mx)) mx=dp[j];
    }
    if(mx.first!=-1) dp[x]=pluss(dp[x],mx);
    // cout<<x<<" "<<dp[x].first<<"/"<<dp[x].second<<endl;
}

signed main(){

    read(t);
    while(t--){
        read(n);idx=0;
        for(int i=1;i<=n;i++) h[i]=-1;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }
        for(int i=1,k;i<=n;i++){
            read(k);
            tr[i]={15,k};
        }
        dfs(1,0);
        ll g=gcd(dp[1].first,dp[1].second);
        cout<<dp[1].first/g<<"/"<<dp[1].second/g<<endl;
    }

    return 0;
}