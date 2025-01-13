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
int a1,a2,b1,b2;
int a,b;

int main(){

    read(t);
    while(t--){
        read(a);read(b);
        a1=0,b1=0,a2=0,b2=0;
        while(a%6==0) a1++,a/=6;
        while(a%5==0) a2++,a/=5;
        while(b%6==0) b1++,b/=6;
        while(b%5==0) b2++,b/=5;

        if(a!=b){
            cout<<-1<<endl;
            continue;
        }

        if(a1<b1||a2>b2){
            cout<<-1<<endl;
            continue;
        }

        cout<<a1-a2+b2-b1<<endl;
    }

    return 0;
}