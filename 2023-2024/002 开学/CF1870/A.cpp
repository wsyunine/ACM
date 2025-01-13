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

int main(){

    read(t);
    while(t--){
        int n,k,x,ans=0;
        read(n),read(k),read(x);

        if(k>n){
            cout<<-1<<endl;
            continue;
        }

        if(x<k-1){
            cout<<-1<<endl;
            continue;
        }

        ans+=k*(k-1)/2;

        if(k==x) x--;
        ans+=(n-k)*x;
        cout<<ans<<endl;
    }

    return 0;
}