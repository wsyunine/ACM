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
int mapp[2010][2010];
string op;

int main(){

    read(n);
    for(int i=1;i<=n;i++){
        cin>>op;
        for(int j=1;j<=n;j++){
            mapp[i][j]=(op[j-1]=='.')?0:1;
        }
    }

    bool idea=1;
    for(int i=1;i<=n;i++){
        int di=0;
        for(int j=1;j<=n;j++){
            if(mapp[i][j]) di++;
            if(di>1){idea=0;break;}
        }
    }

    if(!idea){cout<<"No"<<endl;return 0;}
    
    for(int i=1;i<=n;i++){
        int di=0;
        for(int j=1;j<=n;j++){
            if(mapp[j][i]) di++;
            if(di>1){idea=0;break;}
        }
    }

    if(!idea){cout<<"No"<<endl;return 0;}
    else cout<<"Yes"<<endl;

    return 0;
}