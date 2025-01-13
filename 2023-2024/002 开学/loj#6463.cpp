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

int n,a[N];

void solve(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);

    if(n%2==0){
        cout<<2<<endl;
        cout<<1<<" "<<n<<endl<<1<<" "<<n<<endl;
        return;
    }

    cout<<4<<endl;
    cout<<1<<" "<<n-1<<endl;
    cout<<1<<" "<<n-1<<endl;
    cout<<n-1<<" "<<n<<endl;
    cout<<n-1<<" "<<n<<endl;
    return;
}   

int main(){

    int t;
    read(t);
    while(t--){
        solve();
    }

    return 0;
}