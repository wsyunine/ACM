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
int x,m;
bool s[1000010];

signed main(){

    read(t);
    while(t--){
        read(x),read(m);
        int res=0;
        for(int i=1;i<=x;i++) s[i]=0;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                if((x^i)<=m) s[i]=1,res++;
            }
            if(x%i==0&&i*i!=x){
                if((x^(x/i))<=m) s[x/i]=1,res++;
            }
        }

        for(int i=1;i<=min(1000000ll,x*2);i++){
            if(s[i]) continue;
            if((i^x)&&(i^x)<=m&&((i^x)%i==0)) res++;
        }

        cout<<res<<endl;
    }

    return 0;
}