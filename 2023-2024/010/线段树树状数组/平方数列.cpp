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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const ll Mod=1e9+7;
int n,m;

ll t[4*N];
int tag1[4*N],tag2[4*N],tag3[4*N];

ll calc(ll x){
    return x*(x+1)*(2*x+1)/6;
}

ll cal(ll x){
    return x*(x+1)/2;
}

void pushup(int x){
    t[x]=(t[x<<1]+t[x<<1|1])%Mod;
}

void pushdown(int x,int l,int r){
    if(tag1[x]){
        int mid=(l+r)>>1;
        t[x<<1]+=(ll)(mid-l+1)*(ll)tag1[x]%Mod;
        t[x<<1|1]+=(ll)(r-mid)*(ll)tag1[x]%Mod;
        tag1[x<<1]+=tag1[x];
        tag1[x<<1|1]+=tag1[x];
        tag1[x]=0;
    }
    if(tag2[x]){
        int mid=(l+r)>>1;
        t[x<<1]+=(ll)tag2[x]*(calc(mid)-calc(l-1))%Mod;
        t[x<<1|1]+=(ll)tag2[x]*(calc(r)-calc(mid))%Mod;
        tag2[x<<1]+=tag2[x];
        tag2[x<<1|1]+=tag2[x];
        tag2[x]=0;
    }
    if(tag3[x]){
        int mid=(l+r)>>1;
        t[x<<1]=(t[x<<1]+Mod-2ll*(ll)tag3[x]*(cal(mid)-cal(l-1))%Mod)%Mod;
        t[x<<1|1]=(t[x<<1|1]+Mod-2ll*(ll)tag3[x]*(cal(r)-cal(mid))%Mod)%Mod;
        tag3[x<<1]+=tag3[x];
        tag3[x<<1|1]+=tag3[x];
        tag3[x]=0;
    }
}

void change1(int x,int l,int r,int cl,int cr,ll v){
    if(cl<=l&&cr>=r){
        (t[x]+=(ll)(r-l+1)*v%Mod)%=Mod;
        tag1[x]+=v;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change1(x<<1,l,mid,cl,cr,v);
    if(cr>mid) change1(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

void change2(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r){
        (t[x]+=(calc(r)-calc(l-1))%Mod)%=Mod;
        tag2[x]+=1;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change2(x<<1,l,mid,cl,cr);
    if(cr>mid) change2(x<<1|1,mid+1,r,cl,cr);
    pushup(x);
}

void change3(int x,int l,int r,int cl,int cr,int v){
    if(cl<=l&&cr>=r){
        t[x]=(t[x]+Mod-2*(ll)(cal(r)-cal(l-1))*v%Mod)%Mod;
        tag3[x]+=v;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change3(x<<1,l,mid,cl,cr,v);
    if(cr>mid) change3(x<<1|1,mid+1,r,cl,cr,v);
    pushup(x);
}

int query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return t[x];
    pushdown(x,l,r);
    int mid=(l+r)>>1,res=0;
    if(ql<=mid) (res+=query(x<<1,l,mid,ql,qr))%=Mod;
    if(qr>mid) (res+=query(x<<1|1,mid+1,r,ql,qr))%=Mod;
    pushup(x);
    return res;
}

signed main(){

    read(n),read(m);

    for(int i=1;i<=m;i++){
        int opt,l,r;
        read(opt),read(l),read(r);
        if(opt==1){
            change1(1,1,n,l,r,(l-1)*(l-1));
            change2(1,1,n,l,r);
            change3(1,1,n,l,r,l-1);
        }else{
            cout<<query(1,1,n,l,r)<<endl;
        }
    }

    return 0;
}