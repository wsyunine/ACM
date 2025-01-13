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

int n,m;
int a[N],tag[N];

void pushdown(int x,int l,int r){
    if(!tag[x]) return;
    tag[x<<1]^=1;
    tag[x<<1|1]^=1;
    tag[x]=0;
}

void change(int x,int l,int r,int cl,int cr){
    if(cl<=l&&cr>=r){
        tag[x]^=1;
        return;
    }
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(cl<=mid) change(x<<1,l,mid,cl,cr);
    if(cr>mid) change(x<<1|1,mid+1,r,cl,cr);
}

int query(int x,int l,int r,int p){
    if(l==r){return tag[x];}
    pushdown(x,l,r);
    int mid=(l+r)>>1;
    if(p<=mid) return query(x<<1,l,mid,p);
    else return query(x<<1|1,mid+1,r,p);
}

int main(){

    read(n),read(m);
    
    for(int i=1;i<=m;i++){
        int opt,l,r;
        read(opt);
        if(opt==1){
            read(l),read(r);
            change(1,1,n,l,r);
        }else{
            read(l);
            printf("%d\n",query(1,1,n,l));
        }
    }

    return 0;
}