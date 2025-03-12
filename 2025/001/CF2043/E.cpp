#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define int long long
template <typename T>
inline void read(T& x)
{
    x = 0;
    bool flg = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar())
        if(c == '-') flg = 1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    if(flg) x = -x;
}

int T;
int n,m;
int a[1010][1010],b[1010][1010];

int e[N],ne[N],h[N],idx,vis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int x){ 
    vis[x]=-1;
    bool res=false;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(vis[j]==-1) res|=1;
        else if(vis[j]==1) res|=0;
        else res|=dfs(j);
        if(res) break;
    }
    vis[x]=1;
    return res;
}

void solve() {
    read(n),read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(a[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            read(b[i][j]);
        }
    }

    for(int i=0;i<=30;i++){
        for(int j=1;j<=n+m;j++) h[j]=-1,vis[j]=0;
        idx=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                // cout<<((a[j][k]>>i)&1)<<" ";
                if((b[j][k]>>i)&1) add(j,n+k);
                else add(n+k,j);
            }
            // cout<<endl;
        }

        int idea=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                // cout<<((b[j][k]>>i)&1)<<" ";
                if(((a[j][k]>>i)&1)!=((b[j][k]>>i)&1)){
                    if(((b[j][k]>>i)&1)==1){
                        if(!vis[n+k]) idea|=dfs(n+k);
                    }else{
                        if(!vis[j]) idea|=dfs(j);
                    }
                }
                if(idea){
                    cout<<"No"<<endl;
                    return;
                }
            }
            // cout<<endl;
        }
    }

    cout<<"Yes"<<endl; 
}

signed main() {
    read(T);
    while(T--) {
        solve();
    }
    return 0;
}