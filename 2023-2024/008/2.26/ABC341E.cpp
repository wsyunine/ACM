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
#define N 2000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int q;
string s;

struct node{
    int tl,tr,tg,ts;
    node(int tl,int tr,int ts) : tl(tl),tr(tr),ts(ts) {}
    node(){}
}t[N];

void pushup(int x){
    t[x].ts=(t[x<<1].ts&&t[x<<1|1].ts)&&(t[x<<1].tr+t[x<<1|1].tl==1);
    t[x].tl=t[x<<1].tl;
    t[x].tr=t[x<<1|1].tr;
}

void build(int x,int l,int r){
    if(l==r) return t[x].tl=t[x].tr=s[l-1]-'0',t[x].ts=1,t[x].tg=0,void();
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}

void pushdown(int x,int l,int r){
    if(!t[x].tg) return;
    t[x<<1].tl=!t[x<<1].tl;
    t[x<<1].tr=!t[x<<1].tr;
    t[x<<1|1].tl=!t[x<<1|1].tl;
    t[x<<1|1].tr=!t[x<<1|1].tr;
    t[x<<1].tg^=t[x].tg;
    t[x<<1|1].tg^=t[x].tg;
    t[x].tg=0;
}

void change(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r) return t[x].tl=!t[x].tl,t[x].tr=!t[x].tr,t[x].tg=!t[x].tg,void();
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change(x<<1,l,mid,cl,cr);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr);
    pushup(x);
}

node query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r) return node(t[x].tl,t[x].tr,t[x].ts);
    int mid=(l+r)>>1;
    pushdown(x,l,r);
    if(qr<=mid) return query(x<<1,l,mid,ql,qr);
    else if(ql>mid) return query(x<<1|1,mid+1,r,ql,qr);
    else{
        node a=query(x<<1,l,mid,ql,qr);
        node b=query(x<<1|1,mid+1,r,ql,qr);
        node c;
        c.ts=(a.ts&&b.ts)&&(a.tr+b.tl==1);
        c.tl=a.tl;
        c.tr=b.tr;
        return c;
    }
}

int main(){

    read(n),read(q);
    cin>>s;

    build(1,1,n);

    for(int i=1;i<=q;i++){
        int opt,l,r;
        read(opt),read(l),read(r);
        if(opt==1){
            change(1,1,n,l,r);
        }else{
            if(query(1,1,n,l,r).ts){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }

    return 0;
}