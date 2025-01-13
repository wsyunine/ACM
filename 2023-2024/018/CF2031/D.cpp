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

int T;
int n;
int a[N];
int t[4*N],lp[N],res[N];
vector<pair<int,int>> s;

void pushup(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return t[x]=0,void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void change(int x,int l,int r,int p,int v){
    if(l==r) return t[x]=v,void();
    int mid=(l+r)>>1;
    if(p<=mid) change(x<<1,l,mid,p,v);
    else change(x<<1|1,mid+1,r,p,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res=max(res,query(x<<1,l,mid,ql,qr));
    if(qr>mid) res=max(res,query(x<<1|1,mid+1,r,ql,qr));
    return res;
}

int main(){

    read(T);
    while(T--){
        read(n);
        s.clear();
        for(int i=1;i<=n;i++) read(a[i]),s.push_back({a[i],i}),lp[i]=0,res[i]=0;
        sort(s.begin(),s.end());
        build(1,1,n);

        int op=s[0].second;
        lp[s[0].second]=s[0].second;
        for(int i=1;i<n;i++){
            lp[s[i].second]=max(s[i].second,op);
            op=max(op,s[i].second);
        }

        for(int i=n-1;i>=0;i--){
            int p=s[i].second;
            res[p]=max(query(1,1,n,1,lp[p]),a[p]);
            change(1,1,n,p,res[p]);
        }

        for(int i=1;i<=n;i++) printf("%d ",res[i]);
        cout<<endl;
    }

    return 0;
}