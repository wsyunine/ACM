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
int a[N],sum[N];

int t[N];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void pushup(int x){
    t[x]=gcd(t[x<<1],t[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return t[x]=a[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) res=gcd(query(x<<1,l,mid,ql,qr),res);
    if(qr>mid) res=gcd(query(x<<1|1,mid+1,r,ql,qr),res);
    return res;
}

void solve() {
    read(n);
    sum[0]=0;
    for(int i=1;i<=n;i++) read(a[i]),sum[i]=sum[i-1]^a[i];

    build(1,1,n);

    int res=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((sum[j]^sum[i-1])==query(1,1,n,i,j)){
                res++;
            }
        }
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