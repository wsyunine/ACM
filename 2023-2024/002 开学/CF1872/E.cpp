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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

long long t0[4*N],t1[4*N],a[N];
int tag[4*N],n,m;
string b;
bool bl[N];

void pushup(int x){
    t1[x]=t1[x<<1]^t1[x<<1|1];
    t0[x]=t0[x<<1]^t0[x<<1|1];
}

void build(int x,int l,int r){
    t0[x]=t1[x]=tag[x]=0;
    if(l==r){
        if(bl[l]) t1[x]=a[l];
        else t0[x]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    swap(t0[x<<1],t1[x<<1]);
    swap(t0[x<<1|1],t1[x<<1|1]);
    tag[x]=0;
    tag[x<<1]^=1;
    tag[x<<1|1]^=1;
}

void change(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r){
        swap(t0[x],t1[x]);
        tag[x]^=1;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(cl<=mid) change(x<<1,l,mid,cl,cr);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr);
    pushup(x);
}

int main(){

    int t;
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        cin>>b;
        for(int i=0;i<n;i++){
            if(b[i]=='1') bl[i+1]=1;
            else bl[i+1]=0;
        }

        build(1,1,n);

        // cout<<t0[1]<<" "<<t1[1]<<endl;

        read(m);

        for(int i=1;i<=m;i++){
            int opt,x,y;
            read(opt);
            if(opt==1){
                read(x),read(y);
                change(1,1,n,x,y);
            }else{
                read(x);
                // pushdown(1,1,n);
                if(x) cout<<t1[1]<<" ";
                else cout<<t0[1]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}