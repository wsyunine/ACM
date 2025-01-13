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
#define N 200010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,q;
int num[N];
int e[N],ne[N],h[N],idx;
int dfn[N],op_dfn=0;
int op_q=1;
int ans[N];
int tr[N];

void add_t(int x,int y){
    for(;x<=n;x+=x&(-x)) tr[x]+=y;
}

int query_t(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=tr[x];
    return res;
}

struct node{
    int l,r,x;
    int op;
}qq[N];

bool cmp(node a,node b){
    return dfn[a.x]<dfn[b.x];
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    dfn[x]=++op_dfn;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
    }
}

void dfs2(int x,int fa){
    int tt=op_q;
    while(op_q<=q&&qq[op_q].x==x) ans[qq[op_q].op]-=(query_t(qq[op_q].r)-query_t(qq[op_q].l-1)),op_q++;
    int ee=op_q;
    add_t(num[x],1);
    
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs2(j,x);
    }
    for(int i=tt;i<ee;i++){
        ans[qq[i].op]+=(query_t(qq[i].r)-query_t(qq[i].l-1));
    }
}

int main(){

    read(t);
    while(t--){
        memset(h,-1,sizeof h);
        memset(tr,0,sizeof tr);
        op_dfn=0;idx=0;

        read(n),read(q);op_dfn=0;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }
        for(int i=1,x;i<=n;i++) read(x),num[x]=i;

        for(int i=1;i<=q;i++){
            read(qq[i].l),read(qq[i].r),read(qq[i].x);
            qq[i].op=i;ans[i]=0;
        }
        
        dfs1(1,0);

        sort(qq+1,qq+1+q,cmp);

        op_q=1;
        dfs2(1,0);

        for(int i=1;i<=q;i++){
            if(ans[i]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;
    }

    return 0;
}