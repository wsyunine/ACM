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

int a[5];
int ans=0;

int main(){

    read(a[0]),read(a[1]),read(a[2]),read(a[3]),read(a[4]);
    ans=a[0]+a[1]+a[2]+a[3]+a[4]-4;
    for(int i=0;i<5;i++) if(!a[i]) ans++;
    if(!a[0]&&!a[1]&&!a[2]&&!a[3]&&!a[4]) ans=0;
    cout<<ans<<endl;
    

    return 0;
}