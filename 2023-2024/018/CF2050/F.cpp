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

int t;
int n,q;
int a[N],b[N];

int T[N];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void pushup(int x){
    T[x]=gcd(T[x<<1],T[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return T[x]=b[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return T[x];
    int mid=(l+r)>>1,res;
    if(qr<=mid){
        res=query(x<<1,l,mid,ql,qr);
    }else if(ql>mid){
        res=query(x<<1|1,mid+1,r,ql,qr);
    }else{
        res=gcd(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));
    }
    return res;
}

int main(){

    read(t);
    while(t--){
        read(n),read(q);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) b[i]=abs(a[i]-a[i-1]);
        build(1,1,n);
        while(q--){
            int l,r;
            read(l),read(r);

            if(l==r) printf("0 ");
            else printf("%d ",query(1,1,n,l+1,r));
        }
        cout<<endl;
    }

    return 0;
}