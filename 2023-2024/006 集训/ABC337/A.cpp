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

int n;
int x[N],y[N],xx=0,yy=0;

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(x[i]),xx+=x[i],read(y[i]),yy+=y[i];

    if(xx>yy){
        cout<<"Takahashi"<<endl;
    }else if(xx<yy){
        cout<<"Aoki"<<endl;
    }else cout<<"Draw"<<endl;

    return 0;
}