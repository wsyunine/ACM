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

int t;
int m,n;
int a[N],b[N],dp[N];
int tr[N];

void pushup(int x){
    tr[x]=min(tr[x<<1],tr[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r){tr[x]=a[l];return;}
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int query(int x,int l,int r,int v){
    if(l==r) return l;
    if(tr[x]>=v) return 0;
    else{
        int mid=(l+r)>>1;
        if(tr[x<<1]<v) return query(x<<1,l,mid,v);
        else if(tr[x<<1|1]<v) return query(x<<1|1,mid+1,r,v);
        else return 0;
    }
}

signed main(){

    read(t);
    while(t--){
        read(n),read(m);
        for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
        
        build(1,1,n);

        stack<int> s;
        for(int i=n;i>=1;i--){
            while(s.size()&&a[s.top()]>=a[i]) s.pop();
            s.push(i);
            dp[i]=s.size();
        }

        dp[0]=0;
        for(int i=1;i<=m;i++){
            int op,po;
            read(op);
            po=query(1,1,n,-op);
            printf("%lld\n",n-dp[po]);
        }
    }

    return 0;
}