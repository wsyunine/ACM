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
int mapp[100][100],vis[100][100];
const int sx[4]={0,1,0,-1};
const int sy[4]={1,0,-1,0};

void dfs(int x,int y,int d,int s){
    if(x==(n+1)/2&&y==(n+1)/2) return;
    vis[x][y]=1;
    mapp[x][y]=s;
    if(x+sx[d]>n||x+sx[d]<1||y+sy[d]>n||y+sy[d]<1||vis[x+sx[d]][y+sy[d]]){
        d=(d+1)%4;
        dfs(x+sx[d],y+sy[d],d,s+1);
    }else{
        dfs(x+sx[d],y+sy[d],d,s+1);
    }
}

int main(){

    read(n);

    dfs(1,1,0,1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==(n+1)/2&&j==(n+1)/2) cout<<"T ";
            else cout<<mapp[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}