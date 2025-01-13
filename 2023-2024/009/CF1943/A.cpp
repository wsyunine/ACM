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
#define N 500010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n,a[N],s[N];

int main(){

    read(t);
    while(t--){
        read(n);
        memset(s,0,sizeof s);
        for(int i=1;i<=n;i++) read(a[i]),s[a[i]]++;

        bool fg=0;
        for(int i=0;i<=n+1;i++){
            if(s[i]==1&&!fg){
                fg=1;
            }else if(s[i]<2){
                cout<<i<<endl;
                break;
            }
        }
    }
    
    return 0;
}