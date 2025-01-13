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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int m,k,h;

signed main(){
    
    read(t);
    while(t--){
        int ans=0;
        read(m),read(k),read(h);
        if(h<=m){
            cout<<h<<endl;
        }else if(m<=k){
            cout<<m<<endl;
        }else if(h<=m+k){
            cout<<m<<endl;
        }else{
            int op=h-m-k;
            ans=m+op/m*(m-k)+(op%m>=(m-k)?m-k:op%m);
            cout<<ans<<endl;
        }
        
    }
    
}