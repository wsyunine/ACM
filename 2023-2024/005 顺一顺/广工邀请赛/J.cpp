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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,m,x,y;
int mapp[1010][1010],vis[1010][1010];
ll pos,ans;
priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> q;

int main(){

    memset(vis,0,sizeof vis);
    read(n),read(m);
    read(x),read(y);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) read(mapp[i][j]);
    }
    pos=0;ans=0;vis[x][y]=1;

    q.push(make_pair(mapp[x][y],make_pair(x,y)));
    while(q.size()){
        auto op=q.top();
        q.pop();
        int xx=op.second.first,yy=op.second.second;
        if(op.first>pos) ans+=(op.first-pos),pos=2*op.first;
        else pos+=op.first;
        if(xx==x&&yy==y) pos-=op.first;
        if(xx>1&&vis[xx-1][yy]==0){
            vis[xx-1][yy]=1;
            q.push(make_pair(mapp[xx-1][yy],make_pair(xx-1,yy)));
        }
        if(yy>1&&vis[xx][yy-1]==0){
            vis[xx][yy-1]=1;
            q.push(make_pair(mapp[xx][yy-1],make_pair(xx,yy-1)));
        }
        if(xx<n&&vis[xx+1][yy]==0){
            vis[xx+1][yy]=1;
            q.push(make_pair(mapp[xx+1][yy],make_pair(xx+1,yy)));
        }
        if(yy<m&&vis[xx][yy+1]==0){
            vis[xx][yy+1]=1;
            q.push(make_pair(mapp[xx][yy+1],make_pair(xx,yy+1)));
        }
    }

    if(ans==mapp[x][y]){
        cout<<"No cheating need."<<endl;
    }else cout<<ans<<endl;

    return 0;
}