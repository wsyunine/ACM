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

int t;
int n;
int vis[1010];
int v[1010][1010];
int mapp[1010][1010];

void dfs(int a,int b){
    vis[a]=1,vis[b]=1;
    v[a][b]=v[b][a]=1;
    cout<<"? "<<a<<" "<<b<<endl;
    fflush(stdout);
    int res;
    cin>>res;
    if(a==res){
        mapp[a][b]=mapp[b][a]=1;
    }else{
        if(!v[a][res]) dfs(a,res);
        if(!v[res][b]) dfs(res,b);
    }
}

int main(){

    read(t);
    while(t--){
        for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) v[i][j]=0,mapp[i][j]=0,vis[i]=0;
        read(n);
        
        for(int i=2;i<=n;i++){
            if(!vis[i]) dfs(1,i);
        }

        cout<<"! ";
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(mapp[i][j]) cout<<i<<" "<<j<<" ";
            }
        }
        fflush(stdout);
    }

    return 0;
}