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
#define N 1000010
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m;
int mapp[N];
char s;
int x,y;

int val[2*N],key[2*N],siz[2*N],ls[2*N],rs[2*N];
ll sum[2*N];
int rt=0,cnt=0;

void pushup(int x){
    siz[x]=siz[ls[x]]+siz[rs[x]]+1;
    sum[x]=sum[ls[x]]+sum[rs[x]]+val[x];
}

int new_node(int v){
    siz[++cnt]=1;
    val[cnt]=sum[cnt]=v;
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

int query1(int v){
    int x,y;
    split(rt,v,x,y);
    int res=siz[y];
    merge(rt,x,y);
    return res;
}

ll query2(int v){
    int x,y;
    split(rt,v,x,y);
    ll res=sum[x];
    merge(rt,x,y);
    return res;
}

int main(){

    read(n),read(m);

    while(m--){
        cin>>s;
        read(x),read(y);
        if(s=='U'){
            if(mapp[x]) del(mapp[x]);
            ins(y);
            mapp[x]=y;
        }else{
            if(query2(y)>=(ll)max(0,x-query1(y))*(ll)y) cout<<"TAK"<<endl;
            else cout<<"NIE"<<endl;
        }
    }

    return 0;
}