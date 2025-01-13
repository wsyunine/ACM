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

double x,y;
double xx,yy;

int main(){

    cin>>x>>y;
    xx=0.5*x+0.5*y;
    yy=0.5*sqrt(3)*x-0.5*sqrt(3)*y;

    cout<<fixed<<setprecision(6)<<xx<<" "<<yy<<endl;

    return 0;
}