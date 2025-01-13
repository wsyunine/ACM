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
#define N 1000010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int a[N],b[N],c[N];
int p[100],suma=0,sumb=0;

void ins(int x){
    for(int i=63;i>=0;i--){
        if((x&(1ll<<i))==0) continue;
        if(!p[i]){p[i]=x;return;}
        else x^=p[i]; 
    }
}

signed main(){

    read(t);

    while(t--){
        read(n);suma=sumb=0;
        for(int i=0;i<64;i++) p[i]=0;
        for(int i=1;i<=n;i++) read(a[i]),suma=suma^a[i];
        for(int i=1;i<=n;i++) read(b[i]),c[i]=a[i]^b[i],ins(c[i]),sumb=sumb^b[i];

        int id=0;
        for(int i=63;i>=0;i--){
            if(!(suma&(1ll<<i)) && !(sumb&(1ll<<i))) continue;
            if((suma&(1ll<<i)) && (sumb&(1ll<<i))){
                suma^=p[i],sumb^=p[i];
                continue;
            }
            if(max(suma^p[i],sumb^p[i])<max(suma,sumb)){
                suma=suma^p[i],sumb=sumb^p[i];
            }
        }

        cout<<max(suma,sumb)<<endl;
    }

    return 0;
}