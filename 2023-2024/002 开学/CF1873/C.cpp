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

int mapp[11][11];
int t;

int main(){

    for(int i=5;i>=1;i--){
        for(int j=1;j<=10;j++){
            mapp[i][j]=i;
        }
        for(int j=1;j<=10;j++){
            mapp[10-i+1][j]=i;
        }
    }

    for(int i=1;i<=5;i++){
        for(int j=i;j<=10-i+1;j++){
            mapp[j][i]=i;
        }
        for(int j=i;j<=10-i+1;j++){
            mapp[j][10-i+1]=i;
        }
    }

    read(t);
    while(t--){
        int ans=0;
        string p;
        for(int i=1;i<=10;i++){
            cin>>p;
            for(int j=0;j<10;j++){
                if(p[j]=='X') ans+=mapp[i][j+1];
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}