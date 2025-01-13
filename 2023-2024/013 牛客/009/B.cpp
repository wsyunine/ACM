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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const ll Mod=998244353;

int n;
int m;
int a[N];
int s[N],pre[N];
ll dp[N];

vector<vector<pair<int,int>>> ope1(N),ope2(N);

ll t[4*N],tag[4*N];

void pushup(int x){
    t[x]=(t[x<<1]+t[x<<1|1])%Mod;
}

void change(int x,int l,int r,int p,int v){
    if(l==r) return t[x]=v,void();
    int mid=(l+r)>>1;
    if(p<=mid) change(x<<1,l,mid,p,v);
    else change(x<<1|1,mid+1,r,p,v);
    if(!tag[x]) pushup(x);
}

void modify(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r){
        tag[x]+=v;
        if(tag[x]){
            t[x]=0;
        }else if(l==r){
            t[x]=dp[l];
        }else{
            t[x]=(t[x<<1]+t[x<<1|1])%Mod;
        }
        return;
    }
    int mid=(l+r)>>1;
    if(cl<=mid) modify(x<<1,l,mid,cl,cr,v);
    if(cr>mid) modify(x<<1|1,mid+1,r,cl,cr,v);
    if(!tag[x]) pushup(x);
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1,k;i<=m;i++) read(s[i]);

    vector<vector<int>> u(n+1);
    for(int i=1;i<=n;i++){
        if(!u[a[i]].size()) u[a[i]].push_back(0);
        u[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<u[i].size();j++){
            for(int k=1;k<=m;k++){
                if(j+s[k]<u[i].size()) ope1[u[i][j+s[k]]].push_back({u[i][j],u[i][j+1]-1});
                if(j+s[k]+1<u[i].size()) ope2[u[i][j+s[k]+1]].push_back({u[i][j],u[i][j+1]-1});
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<a[i]<<":"<<endl;
    //     for(int j=0;j<ope1[i].size();j++){
    //         cout<<ope1[i][j].first<<" "<<ope1[i][j].second<<endl;
    //     }
    //     cout<<endl;
    //     for(int j=0;j<ope2[i].size();j++){
    //         cout<<ope2[i][j].first<<" "<<ope2[i][j].second<<endl;
    //     }
    // }

    dp[1]=1;
    change(1,1,n+1,1,1);
    for(int i=2;i<=n+1;i++){
        for(int j=0;j<ope1[i-1].size();j++){
            modify(1,1,n+1,ope1[i-1][j].first+1,ope1[i-1][j].second+1,1);
        }
        for(int j=0;j<ope2[i-1].size();j++){
            modify(1,1,n+1,ope2[i-1][j].first+1,ope2[i-1][j].second+1,-1);
        }
        dp[i]=t[1];
        // cout<<t[1]<<endl;
        change(1,1,n+1,i,dp[i]);
        // cout<<t[1]<<endl;
    }

    cout<<dp[n+1]<<endl;

    return 0;
}