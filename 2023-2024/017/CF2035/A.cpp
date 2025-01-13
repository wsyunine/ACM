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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=2*n;i++) read(a[i]);
        int op1=0,op2=0;
        for(int i=1;i<=2*n;i++) (a[i]==0)?op2++:op1++;

        cout<<((op1%2==0)?0:1)<<" ";
        cout<<((op1>n)?n-(op1-n):op1)<<endl;

    }

    return 0;
}