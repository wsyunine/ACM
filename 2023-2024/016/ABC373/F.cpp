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


int n,W;
int f[3010][3010];
int w[N],v[N];
int dp[3010][3010];

int main(){

    read(n);read(W);
    for(int i=1;i<=n;i++){
        read(w[i]);read(v[i]);
    }

    priority_queue<int> q;
    for(int i=1;i<=n;i++) q.push(v[i]-1);
    for(int i=1;i<=n;i++)

    return 0;
}