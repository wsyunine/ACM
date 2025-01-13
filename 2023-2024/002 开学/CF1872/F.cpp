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

int n;
int vis[N];
int d[N],a[N],c[N];
vector<int> ans;

void dfs(int x){
    // cout<<x<<endl;
    ans.push_back(x);
    vis[x]=1;
    if(--d[a[x]]==0) dfs(a[x]);
}

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first==b.first?a.second<b.second:a.first<b.first;
}

int main(){

    int t;
    read(t);
    while(t--){
        ans.clear();
        read(n);
        for(int i=1;i<=n;i++) d[i]=0;
        for(int i=1;i<=n;i++) read(a[i]),vis[i]=0,d[a[i]]++;
        for(int i=1;i<=n;i++) read(c[i]);

        for(int i=1;i<=n;i++){
            if(d[i]==0&&vis[i]==0) dfs(i);
        }

        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            vector<pair<int,int> > sp;
            sp.push_back(make_pair(c[i],i));
            for(int j=a[i];j!=i;j=a[j]){
                sp.push_back(make_pair(c[j],j));
                vis[j]=1;
            }
            sort(sp.begin(),sp.end(),cmp);
            for(int j=a[sp[0].second];j!=sp[0].second;j=a[j]){
                ans.push_back(j);
            }
            ans.push_back(sp[0].second);
        }

        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}