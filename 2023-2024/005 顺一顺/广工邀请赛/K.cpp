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
int n;

int calc(int x){
    int res=0;
    for(int i=2;i*i<=x;i++){
        if(x%i) continue;
        res++;
        while(x%i==0) x/=i;
    }
    if(x!=1) res++;
    return res;
}

signed main(){

    read(t);
    while(t--){
        read(n);

        int ans=0;
        while(n){
            ans++;
            if(calc(n)>1){
                break;
            }
            n=n/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}