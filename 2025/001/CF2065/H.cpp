#include<bits/stdc++.h>
using namespace std;
#define N 800010
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
const int Mod=998244353;

struct node{
    int l,r;
    int sl,sr,res;
    node(){}
    node(int l,int r,int sl,int sr,int res):l(l),r(r),sl(sl),sr(sr),res(res){}
}t[N];

int T;
int n,q;
string s;
int a[N];
int jc[200010];

void pushup(int x){
    ll llen=t[x<<1].r-t[x<<1].l+1;
    ll rlen=t[x<<1|1].r-t[x<<1|1].l+1;
    ll lcnt=jc[llen]-1ll;
    if(lcnt<0) lcnt+=Mod;
    ll rcnt=jc[rlen]-1ll;
    if(rcnt<0) rcnt+=Mod;
    t[x].l=t[x<<1].l;
    t[x].r=t[x<<1|1].r;
    t[x].sl=((ll)t[x<<1|1].sl+(ll)t[x<<1].sl*(rcnt+1ll)%Mod)%Mod;
    t[x].sr=((ll)t[x<<1].sr+(ll)t[x<<1|1].sr*(lcnt+1ll)%Mod)%Mod;
    t[x].res=((ll)t[x<<1].res*(rcnt+1ll)%Mod+(ll)t[x<<1|1].res*(lcnt+1ll)%Mod)%Mod;
    t[x].res=((ll)t[x].res-(ll)t[x<<1].sr*(ll)t[x<<1|1].sl%Mod+Mod)%Mod;
    t[x].res=((ll)t[x].res-(lcnt-(ll)t[x<<1].sr+Mod)*(rcnt-(ll)t[x<<1|1].sl+Mod)%Mod+Mod)%Mod;
}

void build(int x,int l,int r){
    if(l==r) return t[x]=node(l,l,(a[l]==1?1:0),(a[l]==1?1:0),1),void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
    // cout<<t[x].res<<" "<<t[x].l<<" "<<t[x].r<<" "<<t[x].sl<<" "<<t[x].sr<<endl;
}

void modify(int x,int l,int r,int p){
    if(l==r){
        if(a[p]) a[p]=0;
        else a[p]=1;
        t[x]=node(p,p,(a[l]==1?1:0),(a[l]==1?1:0),1);
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) modify(x<<1,l,mid,p);
    else modify(x<<1|1,mid+1,r,p);
    pushup(x);
}

void solve() {
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0') a[i]=0;
        else a[i]=1;
    }
    build(1,1,n);
    // cout<<t[1].res<<" "<<t[1].l<<" "<<t[1].r<<" "<<t[1].sl<<" "<<t[1].sr<<endl;
    read(q);
    while(q--){
        int tmp;
        read(tmp);
        modify(1,1,n,tmp);
        printf("%d ",t[1].res);
    }
    printf("\n");
}

int main() {
    jc[0]=1;
    for(int i=1;i<=2e5;i++) jc[i]=(ll)jc[i-1]*2ll%Mod;
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}