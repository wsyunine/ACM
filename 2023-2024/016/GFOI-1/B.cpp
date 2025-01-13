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
int m;
int q;
vector<int> mapp[100010];
vector<int> dis[55];

void dijk(int id,int st){
    
}

int main(){

    read(n),read(m),read(q);
    for(int i=1;i<=n;i++){
        mapp[i].push_back(0);
        for(int j=1;j<=m;j++){
            int op;
            read(op);
            mapp[i].push_back(op);
        }
    }

    for(int i=1;i<=q;i++){

    }

    return 0;
}