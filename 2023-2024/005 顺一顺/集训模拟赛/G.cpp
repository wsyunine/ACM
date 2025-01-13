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

int t;
int n,m,k;
int h,x,y;
bool mapp[1005][1005][6];
int d[1005][1005][6];
queue<pair<pair<int,int>,int>> q;

void bfs(){
    while(q.size()) q.pop();
    d[n][m][1]=1;
    q.push(make_pair(make_pair(n,m),1));
    while(!q.empty()){
        pair<pair<int,int>,int> opt=q.front();
        q.pop();
        int xx=opt.first.first,yy=opt.first.second;
        int time=opt.second;
        // cout<<xx<<" "<<yy<<" "<<time<<endl;
        int prs=(time-1)%k+1;
        int nxt=time%k+1;

        if(xx!=n&&mapp[xx+1][yy][prs]==0){
            if(!d[xx+1][yy][nxt]&&mapp[xx+1][yy][nxt]==0){
                d[xx+1][yy][nxt]=time+1;
                q.push(make_pair(make_pair(xx+1,yy),time+1));
            }
            if(yy!=m&&!d[xx+1][yy+1][nxt]&&mapp[xx+1][yy+1][prs]==0&&mapp[xx+1][yy+1][nxt]==0){
                d[xx+1][yy+1][nxt]=time+1;
                q.push(make_pair(make_pair(xx+1,yy+1),time+1));
            }
            if(yy!=1&&!d[xx+1][yy-1][nxt]&&mapp[xx+1][yy-1][prs]==0&&mapp[xx+1][yy-1][nxt]==0){
                d[xx+1][yy-1][nxt]=time+1;
                q.push(make_pair(make_pair(xx+1,yy-1),time+1));
            }
        }else if(xx==n||mapp[xx+1][yy][prs]==1){
            for(int i=0;i<=min(h,xx-1);i++){
                if(mapp[xx-i][yy][prs]==1) break;
                if(!d[xx-i][yy][nxt]&&mapp[xx-i][yy][nxt]==0){
                    d[xx-i][yy][nxt]=time+1;
                    q.push(make_pair(make_pair(xx-i,yy),time+1));
                }
                if(yy!=m&&!d[xx-i][yy+1][nxt]&&mapp[xx-i][yy+1][prs]==0&&mapp[xx-i][yy+1][nxt]==0){
                    d[xx-i][yy+1][nxt]=time+1;
                    q.push(make_pair(make_pair(xx-i,yy+1),time+1));
                }
                if(yy!=1&&!d[xx-i][yy-1][nxt]&&mapp[xx-i][yy-1][prs]==0&&mapp[xx-i][yy-1][nxt]==0){
                    d[xx-i][yy-1][nxt]=time+1;
                    q.push(make_pair(make_pair(xx-i,yy-1),time+1));
                }
            }
        }
    }
}

int main(){

    read(t);
    while(t--){
        memset(d,0,sizeof d);
        read(n),read(m),read(k);
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                string s;
                cin>>s;
                for(int op=0;op<m;op++){
                    if(s[op]=='*') mapp[j][op+1][i]=1;
                    else mapp[j][op+1][i]=0;
                }
            }
        }
        read(h),read(x),read(y);

        if(x==n&&y==m){cout<<1<<endl;continue;}

        bfs();

        int ans=0x3f3f3f3f;
        for(int i=1;i<=k;i++) if(d[x][y][i]) ans=min(ans,(int)d[x][y][i]);

        if(ans==0x3f3f3f3f) cout<<-1<<endl;
        else cout<<ans-1<<endl;
    }

    return 0;
}