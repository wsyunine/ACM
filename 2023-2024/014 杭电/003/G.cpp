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

int n;
int a[N],b[N];

int t1[N],t2[N];

void pushup(int x){
    t1[x]=min(t1[x<<1],t1[x<<1|1]);
    t2[x]=max(t2[x<<1],t2[x<<1|1]);
}

void build(int x,int l,int r){
    if(l==r) return t1[x]=t2[x]=b[l],void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void change(int x,int l,int r,int p,int v){
    if(l==r){
        t1[x]=t1[x]+v;
        t2[x]=t2[x]+v;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) change(x<<1,l,mid,p,v);
    else change(x<<1|1,mid+1,r,p,v);
    pushup(x);
}

int query1(int x,int l,int r,int ql,int qr){
    if(ql>qr) return 0;
    if(ql<=l&&qr>=r) return t1[x];
    int mid=(l+r)>>1,res=0x3f3f3f3f;
    if(ql<=mid) res=min(res,query1(x<<1,l,mid,ql,qr));
    if(qr>mid) res=min(res,query1(x<<1|1,mid+1,r,ql,qr));
    return res;
}

int query2(int x,int l,int r,int ql,int qr){
    if(ql>qr) return 0;
    if(ql<=l&&qr>=r) return t2[x];
    int mid=(l+r)>>1,res=-0x3f3f3f3f;
    if(ql<=mid) res=max(res,query2(x<<1,l,mid,ql,qr));
    if(qr>mid) res=max(res,query2(x<<1|1,mid+1,r,ql,qr));
    return res;
}

signed main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    // for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    
    build(1,1,n);

    int q,id,l,x,r;
    read(q);
    while(q--){
        read(id);
        if(id==1){
            read(l),read(r),read(x);
            change(1,1,n,l,x);
            change(1,1,n,r+1,-x);
        }else if(id==2){
            read(l),read(r);
            if(l==r){printf("1\n");continue;}
            if(query1(1,1,n,l+1,r)==0&&query2(1,1,n,l+1,r)==0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else if(id==3){
            read(l),read(r);
            if(l==r){printf("1\n");continue;}
            if(query1(1,1,n,l+1,r)>0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else if(id==4){
            read(l),read(r);
            if(l==r){printf("1\n");continue;}
            if(query2(1,1,n,l+1,r)<0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }else if(id==5){
            read(l),read(r);
            int a=l,b=r;
            while(a<b){
                int mid=(a+b+1)>>1;
                if(query1(1,1,n,mid,mid)>0) a=mid;
                else b=mid-1;
            }
            // cout<<a<<" "<<query1(1,1,n,l+1,a)<<" "<<query2(1,1,n,a+1,r)<<endl;
            if(query1(1,1,n,l+1,a)>0&&query2(1,1,n,a+1,r)<0){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
    }

    return 0;
}