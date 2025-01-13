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
string str;
int vis[1000][1000];
set<pair<int,int>> res;

void dfs(int x,int y,int s){
    if(s==n){res.insert({x,y});return;}
    int sx=x,sy=y;
    if(str[s]=='L') x--;
    if(str[s]=='R') x++;
    if(str[s]=='U') y++;
    if(str[s]=='D') y--;
    if(vis[x+100][y+100]==-1) dfs(sx,sy,s+1);
    else if(vis[x+100][y+100]==1){
        dfs(x,y,s+1);
    }else{
        vis[x+100][y+100]=1;
        dfs(x,y,s+1);
        vis[x+100][y+100]=0;
        vis[x+100][y+100]=-1;
        dfs(sx,sy,s+1);
        vis[x+100][y+100]=0;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    read(n);
    cin>>str;
    int x=0,y=0;

    vis[100][100]=1;
    dfs(0,0,0);
    vis[100][100]=0;

    cout<<res.size()<<endl;
    for(auto i:res) cout<<i.first<<" "<<i.second<<endl;

    return 0;
}