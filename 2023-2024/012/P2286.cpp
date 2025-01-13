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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

const int inf=0x3f3f3f3f3f3f3f3f;
int mod=1000000;

int n,v,op,x,y,z,w,ans=0;
int rt1=0,rt2=0,tot,key[N],val[N],siz[N],ls[N],rs[N];

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

void split(int p,int k,int &a,int &b){
    if(!p){
        a=b=0;
        return;
    }
    if(val[p]<=k) a=cpy(p),split(rs[a],k,rs[a],b),pushup(a);
    else b=cpy(p),split(ls[b],k,a,ls[b]),pushup(b);
}

void insert(int &root,int w){
    split(root,w,x,y);
    merge(x,x,build(w));
    merge(root,x,y);
}

void del(int &root,int w){
    split(root,w,x,y);
    split(x,w-1,x,z);
    merge(z,ls[z],rs[z]);
    merge(x,x,z);
    merge(root,x,y);
}

int query(int p,int k){
    if(k==siz[ls[p]]+1) return val[p];
    if(k<=siz[ls[p]]) return query(ls[p],k);
    else return query(rs[p],k-siz[ls[p]]-1);
}

int query_(int &root,int w){
    split(root,w,x,y);
    int op1,op2;
    if(siz[x]&&siz[y]){
        op1=query(x,siz[x]);
        op2=query(y,1);
        merge(root,x,y);
        return (w-op1<=op2-w)?op1:op2;
    }else if(siz[x]){
        op1=query(x,siz[x]);
        merge(root,x,y);
        return op1;
    }else if(siz[y]){
        op2=query(y,1);
        merge(root,x,y);
        return op2;
    }
    return 0;
}

signed main(){

    read(n);
    while(n--){
        int opt,x;
        read(opt),read(x);
        if(opt==0){
            if(siz[rt2]){
                int op=query_(rt2,x);
                (ans+=abs(x-op))%=mod;
                del(rt2,op);
            }else insert(rt1,x);
        }else{
            if(siz[rt1]){
                int op=query_(rt1,x);
                (ans+=abs(x-op))%=mod;
                del(rt1,op);
            }else insert(rt2,x);
        }
    } 
    cout<<ans<<endl;
    return 0;
}