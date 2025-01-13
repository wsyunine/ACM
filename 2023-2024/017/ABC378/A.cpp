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
int a[5],res=0;

int main(){

    read(a[1]),read(a[2]),read(a[3]),read(a[4]);

    sort(a+1,a+1+4);

    for(int i=1;i<=4;i++){
        if(a[i]==a[i+1]) res++,i++;
    }

    cout<<res<<endl;

    return 0;
}