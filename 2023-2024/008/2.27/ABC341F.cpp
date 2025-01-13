//01背包
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

int n,m;
long long ans=0;
int w[N],a[N],s[N];
int e[N],ne[N],h[N],idx;
int num[N],f[5010];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool cmp(int a,int b){
    return w[a]<w[b];
}

int main(){

    memset(h,-1,sizeof h);
    memset(s,-1,sizeof s);
    read(n),read(m);
    for(int i=1;i<=m;i++){
        int u,v;
        read(u),read(v);
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++) read(w[i]),num[i]=i;
    for(int i=1;i<=n;i++) read(a[i]);

    sort(num+1,num+1+n,cmp);
    for(int i=1;i<=n;i++){
        memset(f,-0x3f3f3f3f,sizeof f);
        f[0]=0;
        int pos=num[i],opt=0;
        for(int j=h[pos];~j;j=ne[j]){
            int k=e[j];
            if(s[k]==-1) continue;
            for(int op=w[pos]-1;op>=w[k];op--){
                f[op]=max(f[op],f[op-w[k]]+s[k]);
                opt=max(opt,f[op]);
            }
        }
        s[pos]=opt+1;
    }

    for(int i=1;i<=n;i++){
        ans+=(long long)a[i]*(long long)s[i];
    }

    cout<<ans<<endl;
    
    return 0;
}