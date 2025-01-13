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

int n,m;
int f[5010],cnt=0;

struct node{
    int st,ed,dis;
}edge[N];

int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

bool cmp(node x,node y){
    return x.dis<y.dis;
}

int main(){

    read(n),read(m);

    for(int i=1;i<=n;i++) f[i]=i;

    for(int i=1;i<=m;i++){
        read(edge[i].st);
        read(edge[i].ed);
        read(edge[i].dis);
    }

    sort(edge+1,edge+1+m,cmp);

    int ans=0;
    for(int i=1;i<=m;i++){
        int a=find(edge[i].st),b=find(edge[i].ed);
        if(a!=b){
            f[a]=b;
            ans+=edge[i].dis;
            cnt++;
        }
    }

    if(cnt<n-1) cout<<"orz"<<endl;
    else cout<<ans<<endl;

    return 0;
}