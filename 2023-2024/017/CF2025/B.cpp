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
#define N 200010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}
const int Mod=1e9+7;

int n;
int a[N],p[N];

int main(){

    p[0]=1;
    for(int i=1;i<=100000;i++) p[i]=p[i-1]*2%Mod;

    read(n);
    for(int i=1;i<=n;i++){read(a[1]);}
    for(int i=1;i<=n;i++){
        read(a[i]);
        cout<<p[a[i]]<<endl;
    }


    return 0;
}