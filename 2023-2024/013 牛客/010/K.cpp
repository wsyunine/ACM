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
int t;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        int x=0;
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            if(a[i]>x) x++;
            else if(a[i]<x) x--;
        }
        cout<<x<<endl;
    }

    return 0;
}