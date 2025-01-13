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
int h,w;
int k,res=0;
string str;
int mapp[20][20],vis[20][20];
stack<pair<int,int>> q,qr;

void dfs(int x,int y,int d){
    if(d==k+1){
        res++;
        return;
    }
    if(mapp[x+1][y]&&!vis[x+1][y]){
        q.push({x+1,y});
        vis[x+1][y]=1;
        dfs(x+1,y,d+1);
        q.pop();
        vis[x+1][y]=0;
    }
    if(mapp[x-1][y]&&!vis[x-1][y]){
        q.push({x-1,y});
        vis[x-1][y]=1;
        dfs(x-1,y,d+1);
        q.pop();
        vis[x-1][y]=0;
    }
    if(mapp[x][y+1]&&!vis[x][y+1]){
        q.push({x,y+1});
        vis[x][y+1]=1;
        dfs(x,y+1,d+1);
        q.pop();
        vis[x][y+1]=0;
    }
    if(mapp[x][y-1]&&!vis[x][y-1]){
        q.push({x,y-1});
        vis[x][y-1]=1;
        dfs(x,y-1,d+1);
        q.pop();
        vis[x][y-1]=0;
    }
}

int main(){

    read(h),read(w),read(k);
    for(int i=1;i<=h;i++){
        cin>>str;
        for(int j=0;j<w;j++){
            if(str[j]=='.') mapp[i][j+1]=1;
            else mapp[i][j+1]=0;
        }
    }
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(mapp[i][j]==0) continue;
            vis[i][j]=1;
            q.push({i,j});
            dfs(i,j,1);
            q.pop();
            vis[i][j]=0;
        }
    }

    cout<<res<<endl;

    return 0;
}