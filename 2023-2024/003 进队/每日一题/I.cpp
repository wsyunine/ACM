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
int vis[1000],cnt=0;

int main(){

    read(n),read(m);
    vector<int> s1(n+1);

    for(int i=1;i<=n;i++){
        read(s1[i]);s1[i]%=1000;
    }

    for(int i=1;i<=m;i++){
        int a;
        read(a);
        vis[a]=1;
    }

    for(int i=1;i<=n;i++){
        if(vis[s1[i]]) cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}