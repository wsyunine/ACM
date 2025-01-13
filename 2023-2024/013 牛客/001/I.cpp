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

int n,m;
int dp[1010][1010][5];
int mapp[1010][1010];
int vis[1010][1010][5];
int q,zp=0,id=0;

void dfs(int x,int y,int z){
    // cout<<x<<" "<<y<<" "<<z<<" "<<id<<" "<<zp<<endl;
    if(x>n||x<1||y>m||y<1){zp=0;return;}
    if(vis[x][y][z]){id=1;return;}
    vis[x][y][z]=1;
    if(z==1){
        if(mapp[x][y]==1){
            if() zp++;
            dfs(x+1,y,2);
            if(id) dp[x][y][2]=zp;
            else{
                dp[x][y][2]=zp;
                zp++;
            }
        }else if(mapp[x][y]==2){
            dfs(x-1,y,1);
            if(id) dp[x][y][1]=zp;
            else{
                dp[x][y][1]=zp;
            }
        }else if(mapp[x][y]==3){
            zp++;
            dfs(x,y+1,4);
            if(id) dp[x][y][4]=zp;
            else{
                dp[x][y][4]=zp;
                zp++;
            }
        }else if(mapp[x][y]==4){
            zp++;
            dfs(x,y-1,3);
            if(id) dp[x][y][3]=zp;
            else{
                dp[x][y][3]=zp;
                zp++;
            }
        }
    }else if(z==2){
        if(mapp[x][y]==1){
            zp++;
            dfs(x-1,y,1);
            if(id) dp[x][y][1]=zp;
            else{
                dp[x][y][1]=zp;
                zp++;
            }
        }else if(mapp[x][y]==2){
            dfs(x+1,y,2);
            if(id) dp[x][y][2]=zp;
            else{
                dp[x][y][2]=zp;
            }
        }else if(mapp[x][y]==3){
            zp++;
            dfs(x,y-1,3);
            if(id) dp[x][y][3]=zp;
            else{
                dp[x][y][3]=zp;
                zp++;
            }
        }else if(mapp[x][y]==4){
            zp++;
            dfs(x,y+1,4);
            if(id) dp[x][y][4]=zp;
            else{
                dp[x][y][4]=zp;
                zp++;
            }
        }
    }else if(z==3){
        if(mapp[x][y]==1){
            dfs(x,y-1,3);
            if(id) dp[x][y][3]=zp;
            else{
                dp[x][y][3]=zp;
            }
        }else if(mapp[x][y]==2){
            zp++;
            dfs(x,y+1,4);
            if(id) dp[x][y][4]=zp;
            else{
                dp[x][y][4]=zp;
                zp++;
            }
        }else if(mapp[x][y]==3){
            zp++;
            dfs(x+1,y,2);
            if(id) dp[x][y][2]=zp;
            else{
                dp[x][y][2]=zp;
                zp++;
            }
        }else if(mapp[x][y]==4){
            zp++;
            dfs(x-1,y,1);
            if(id) dp[x][y][1]=zp;
            else{
                dp[x][y][1]=zp;
                zp++;
            }
        }
    }else if(z==4){
        if(mapp[x][y]==1){
            dfs(x,y+1,4);
            if(id) dp[x][y][4]=zp;
            else{
                dp[x][y][4]=zp;
            }
        }else if(mapp[x][y]==2){
            zp++;
            dfs(x,y-1,3);
            if(id) dp[x][y][3]=zp;
            else{
                dp[x][y][3]=zp;
                zp++;
            }
        }else if(mapp[x][y]==3){
            zp++;
            dfs(x-1,y,1);
            if(id) dp[x][y][1]=zp;
            else{
                dp[x][y][1]=zp;
                zp++;
            }
        }else if(mapp[x][y]==4){
            zp++;
            dfs(x+1,y,2);
            if(id) dp[x][y][2]=zp;
            else{
                dp[x][y][2]=zp;
                zp++;
            }
        }
    }
    vis[x][y][z]=0;
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char op;
            cin>>op;
            if(op=='-') mapp[i][j]=1;
            if(op=='|') mapp[i][j]=2;
            if(op=='/') mapp[i][j]=3;
            if(op=='\\') mapp[i][j]=4;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!dp[i][j][1]){
                zp=0;id=0;
                dfs(i-1,j,1);
                dp[i][j][1]=zp;
            }
            if(!dp[i][j][2]){
                zp=0;id=0;
                dfs(i+1,j,2);
                dp[i][j][2]=zp;
            }
            if(!dp[i][j][3]){
                zp=0;id=0;
                dfs(i,j-1,3);
                dp[i][j][3]=zp;
            }
            if(!dp[i][j][4]){
                zp=0;id=0;
                dfs(i,j+1,4);
                dp[i][j][4]=zp;
            }
        }
    }

    // for(int k=1;k<=4;k++){
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    read(q);

    while(q--){
        int x,y;
        string s;
        read(x),read(y);
        cin>>s;
        if(s[0]=='a'){
            cout<<dp[x][y][1]<<endl;
        }else if(s[0]=='b'){
            cout<<dp[x][y][2]<<endl;
        }else if(s[0]=='l'){
            cout<<dp[x][y][3]<<endl;
        }else if(s[0]=='r'){
            cout<<dp[x][y][4]<<endl;
        }
    }

    return 0;
}