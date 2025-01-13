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
int n,m,res=0;
int a[N],mapp[1010][1010];
string str;
const int df[5]={0,1,5,4,3};

int main(){

    read(t);
    while(t--){
        read(n);read(m);res=0;

        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++){
            cin>>str;
            for(int j=1;j<=m;j++){
                mapp[i][j]=stoi(str.substr(j-1,1));
                if(mapp[i][j]==1) q.push({i,j});
            }
        }
        
        for(int i=1;i<=min(n/2,m/2);i++){
            pair<int,int> lu={i,i},ru={i,m-i+1};
            pair<int,int> ld={n-i+1,i},rd={n-i+1,m-i+1};

            vector<int> op;
            for(int x=lu.second;x<ru.second;x++){
                op.push_back(mapp[i][x]);
            }
            for(int y=i;y<n-i+1;y++){
                op.push_back(mapp[y][m-i+1]);
            }
            for(int x=m-i+1;x>i;x--){
                op.push_back(mapp[n-i+1][x]);
            }
            for(int y=n-i+1;y>i;y--){
                op.push_back(mapp[y][i]);
            }

            int s=op.size();
            for(int k=0;k<s;k++){
                if(op[k]==1&&op[(k+1)%s]==5&&op[(k+2)%s]==4&&op[(k+3)%s]==3) res++;
            }
        }

        cout<<res<<endl;
        
    }

    return 0;
}