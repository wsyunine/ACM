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

int t;
int n;
int res1,res2,res3;

int main(){

    read(t);
    while(t--){
        read(n);

        printf("1 1\n");
        fflush(stdout);
        read(res1);
        int sum1=res1,sum0=res1;

        printf("1 11\n");
        fflush(stdout);
        read(res2);
        int d1=sum1-res2;

        printf("1 01\n");
        fflush(stdout);
        read(res3);
        if(d1==res3){
            printf("0 1 0\n");
        }else printf("0 1 1\n");
        fflush(stdout);
        read(res1);
    }

    return 0;
}