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

const int INF=2147483647;

int n,v,op,x,y,z,w;
int rt[N],tot=0,key[N],val[N],siz[N],ls[N],rs[N];

void pushup(int x){
    siz[x]=siz[ls[x]]+siz[rs[x]]+1;
}

int build(int x){
    val[++tot]=x;
    siz[tot]=1;
    key[tot]=rand();
    return tot;
}

int cpy(int x){
    tot++;
    val[tot]=val[x];
    siz[tot]=siz[x];
    key[tot]=key[x];
    ls[tot]=ls[x];
    rs[tot]=rs[x];
    return tot;
}

void merge(int &p,int a,int b){
    if(!a||!b){
        p=a+b;
        return;
    }
    if(key[a]<key[b]) p=cpy(a),merge(rs[p],rs[p],b);
    else p=cpy(b),merge(ls[p],a,ls[p]);
    pushup(p);
}

void spilt(int p,int k,int &a,int &b){
    if(!p){
        a=b=0;
        return;
    }
    if(val[p]<=k){
        a=cpy(p);
        spilt(rs[a],k,rs[a],b);
        pushup(a);
    }else{
        b=cpy(b);
        spilt(ls[b],k,a,ls[b]);
        pushup(b);
    }
}

void insert(int &root,int w){
    spilt(root,w,x,y);
    merge(x,x,build(w));
    merge(root,x,y);
}

void del(int &root,int w){
    spilt(root,w,x,y);
    spilt(x,w-1,x,z);
    merge(z,ls[z],rs[z]);
    merge(x,x,z);
    merge(root,x,y);
}

int rank_(int &root,int w){
    spilt(root,w-1,x,y);
    int ans=siz[x]+1;
    merge(root,x,y);
    return ans;
}

int query(int p,int k){
    if(k==siz[ls[p]]+1) return val[p];
    if(k<=siz[ls[p]]) return query(ls[p],k);
    else return query(rs[p],k-siz[ls[p]]-1);
}

int from(int &root,int w){
    spilt(root,w-1,x,y);
    if(!siz[x]) return -INF;
    int ans=query(x,siz[x]);
    merge(root,x,y);
    return ans;
}

int nxt(int &root,int w){
    spilt(root,w,x,y);
    if(!siz[y]) return INF;
    int ans=query(y,1);
    merge(root,x,y);
    return ans;
}

int main(){



    return 0;
}