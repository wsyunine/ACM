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
const int Mod=998244353;

int a,b;
int x=0,y=0;

int fpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=a*a%Mod) if(b&1) res=res*a%Mod;
    return res;
}

signed main(){

    read(a),read(b);
    cout<<a*fpow(a+b,Mod-2)%Mod<<" "<<b*fpow(a+b,Mod-2)%Mod<<endl;
    // int p2=fpow(2,Mod-2);

    // int op=1;
    // while(1){
    //     // cout<<x<<" "<<y<<endl;
    //     int aa=x,bb=y;
    //     (op*=p2)%=Mod;
    //     if(a>b){
    //         a-=b;
    //         b+=b;
    //         (x+=op)%=Mod;
    //     }else if(a<b){
    //         b-=a;
    //         a+=a;
    //         (y+=op)%=Mod;
    //     }else{
    //         (x+=op)%=Mod;
    //         (y+=op)%=Mod;
    //     }
    //     if(x==aa&&y==bb) break;
    // }

    // cout<<x<<" "<<y<<endl;

    return 0;
}