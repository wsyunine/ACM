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

int val[4*N],key[4*N],siz[4*N],ls[4*N],rs[4*N];

int rt=0,cnt=0;

void pushup(int x){
    siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}

int new_node(int v){
    siz[++cnt]=1;
    val[cnt]=v;
    key[cnt]=rand();
    return cnt;
}

void split(int pos,int k,int &x,int &y){
    if(!pos){x=y=0;return;}
    if(val[pos]<=k) x=pos,split(rs[pos],k,rs[pos],y);
    else y=pos,split(ls[pos],k,x,ls[pos]);
    pushup(pos);
}

void merge(int &p,int x,int y){
    if(!x||!y) return p=x+y,void();
    if(key[x]<key[y]) p=x,merge(rs[x],rs[x],y);
    else p=y,merge(ls[y],x,ls[y]);
    pushup(p);
}

int kth(int pos,int k){
    while(1){
        if(k<=siz[ls[pos]]) pos=ls[pos];
        else if(k==siz[ls[pos]]+1) return pos;
        else k-=siz[ls[pos]]+1,pos=rs[pos];
    }
}

void ins(int v){
    int x,y;
    split(rt,v,x,y);
    merge(x,x,new_node(v));
    merge(rt,x,y);
}

void del(int v){
    int x,y,z;
    split(rt,v,x,z);
    split(x,v-1,x,y);
    merge(y,ls[y],rs[y]);
    merge(x,x,y);
    merge(rt,x,z);
}

int rank_(int v){
    int x,y;
    split(rt,v-1,x,y);
    int res=siz[x]+1;
    merge(rt,x,y);
    return res;
}

int num(int rk){
    return val[kth(rt,rk)];
}

int pre(int v){
    int x,y;
    split(rt,v-1,x,y);
    int res=val[kth(x,siz[x])];
    merge(rt,x,y);
    return res;
}

int nex(int v){
    int x,y;
    split(rt,v,x,y);
    int res=val[kth(y,1)];
    merge(rt,x,y);
    return res;
}

signed main(){

    read(n);
    while(n--){
        int opt,x;
        read(opt),read(x);
        if(opt==1){
            ins(x);
        }else if(opt==2){
            del(x);
        }else if(opt==3){
            printf("%lld\n",rank_(x));
        }else if(opt==4){
            printf("%lld\n",num(x));
        }else if(opt==5){
            printf("%lld\n",pre(x));
        }else{
            printf("%lld\n",nex(x));
        }
    }

    return 0;
}