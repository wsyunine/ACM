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
double t,v;

int main(){

    cin>>x>>y>>t>>v;

    double op=t*v;
    op=op-(int)op;
    if(op>0.5) op=1-op;
    op=0.25-op/2;
    op=op*4*asin(1);

    cout<<fixed<<setprecision(6)<<2*cos(op)*sqrt(x*x+y*y)<<endl;

    return 0;
}