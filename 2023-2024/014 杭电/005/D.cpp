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

int n,q;
int t;
struct qut{
    int id,r,x,res;
}qur[1000010];
int e[N],ne[N],h[N],idx;
int dfn[N],inv[N],d[N],f[N],top[N],son[N],siz[N],cnt=0;
vector<int> divi[100010];
vector<pair<int,pair<int,int>>> s;

bool cmp1(qut a,qut b){
    return a.x<b.x;
}

bool cmp2(qut a,qut b){
    return a.id<b.id;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

long long lcm(int a,int b){
    return (long long)a*(long long)b/(long long)gcd(a,b);
}

void init(){
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i) divi[j].push_back(i);
    }
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            for(auto k:divi[j]){
                if(k<=i&&lcm(i,k)==j) s.push_back({j,{k,i}});
            }
        }
    }
    sort(s.begin(),s.end());
    // cout<<s.size()<<endl;
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa){
    siz[x]=1;dfn[x]=++cnt,inv[cnt]=x;d[x]=d[fa]+1;
    f[x]=fa;son[x]=0;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x);
        siz[x]+=siz[j];
        if(siz[j]>siz[son[x]]) son[x]=j;
    }
}

void dfs2(int x,int fa){
    top[x]=fa;
    if(son[x]) dfs2(son[x],fa);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==f[x]||j==son[x]) continue;
        dfs2(j,j);
    }
}

int lca(int x,int y){
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]) swap(x,y);
        x=f[top[x]];
    }
    return d[x]<=d[y]?x:y;
}

int tt[N];
void add_(int x,int y){
    if(x<=0) return;
    for(;x<=n;x+=x&(-x)) tt[x]+=y;
}

int query_(int x){
    if(x<=0) return 0;
    int res=0;
    for(;x;x-=x&(-x)) res+=tt[x];
    return res;
}

int main(){

    init();
    read(t);
    while(t--){
        read(n);cnt=0;idx=0;
        for(int i=1;i<=n;i++) h[i]=-1,tt[i]=0;
        for(int i=1;i<n;i++){
            int a,b;
            read(a),read(b);
            add(a,b),add(b,a);
        }
        dfs1(1,0);
        dfs2(1,0);
        // for(int i=1;i<=n;i++) cout<<dfn[i]<<endl;
        read(q);
        for(int i=1;i<=q;i++){
            read(qur[i].r),read(qur[i].x);
            qur[i].id=i;
        }
        sort(qur+1,qur+1+q,cmp1);

        int pos=0;
        for(int i=1;i<=q;i++){
            while(pos<=s.size()&&s[pos].first<=qur[i].x){
                if(s[pos].second.first<=n&&s[pos].second.second<=n){
                    add_(dfn[lca(s[pos].second.first,s[pos].second.second)],s[pos].second.first==s[pos].second.second?1:2);
                    // cout<<s[pos].second.first<<" "<<s[pos].second.second<<endl;
                }
                pos++;
            }
            qur[i].res=query_(dfn[qur[i].r]+siz[qur[i].r]-1)-query_(dfn[qur[i].r]-1);
        }
        sort(qur+1,qur+1+q,cmp2);

        for(int i=1;i<=q;i++){
            cout<<qur[i].res;
            if(i==q) cout<<endl;
            else cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}