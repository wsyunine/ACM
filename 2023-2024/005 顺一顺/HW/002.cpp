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

bool multiple(pair<int,int> s){
    if(s.first%s.second==0) return true;
    else return false;
}

int main(){

    int n;
    read(n);
    for(int i=1,a,b;i<=n;i++) read(a),read(b),cout<<multiple(make_pair(a,b))<<endl;

    return 0;
}