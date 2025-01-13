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
#define llo long long
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define mp make_pair
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,k,L,R;
llo res=0;
llo a[N];
llo f[N][30];
int g[N][30],lgn[N]={-1};
llo s[N];

void init(){
    for(int i=1;i<=n;i++) f[i][0]=s[i],g[i][0]=i,lgn[i]=lgn[i/2]+1;
    for(int j=1;j<=lgn[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int a1=f[i][j-1],a2=f[i+(1<<(j-1))][j-1];
            if(a1>=a2){
                g[i][j]=g[i][j-1];
                f[i][j]=a1;
            }else{
                g[i][j]=g[i+(1<<(j-1))][j-1];
                f[i][j]=a2;
            }
        }
    }
}

pii query(int l,int r){
    if(l>r) return mp(-1e9+7,-1e9+7);
    int len=lgn[r-l+1];
    if(f[l][len]>=f[r-(1<<len)+1][len]){
        return mp(f[l][len],g[l][len]);
    }else{
        return mp(f[r-(1<<len)+1][len],g[r-(1<<len)+1][len]);
    }
}

struct node{
    int v,ll,rr,kk;
    node(int v,int ll,int rr) : v(v),ll(ll),rr(rr),kk(query(ll,rr).second) {};
    friend bool operator < (const node a,const node b){
        return (s[a.kk]-s[a.v-1] < s[b.kk]-s[b.v-1]);
    }
};

priority_queue<node> q;

int main(){

    read(n),read(k),read(L),read(R);

    for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];

    init();

    for(int i=1;i+L-1<=n;i++){
        int ll=min(i+L-1,n),rr=min(i+R-1,n);
        auto [b1,b2]=query(ll,rr);
        // cout<<b1<<" "<<b2<<endl;
        q.push(node(i,ll,rr));
    }

    for(int i=1;i<=k;i++){
        auto st=q.top();
        q.pop();
        res+=s[st.kk]-s[st.v-1];
        if(st.ll<=st.kk-1) q.push(node(st.v,st.ll,st.kk-1));
        if(st.kk+1<=st.rr) q.push(node(st.v,st.kk+1,st.rr));
    }

    cout<<res<<endl;

    return 0;
}