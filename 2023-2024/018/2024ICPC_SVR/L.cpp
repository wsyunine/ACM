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

int main(){

    read(n);
    if(n%6==0){
        cout<<n/3*2+n/2<<endl;
    }else if(n%6==3){
        cout<<n/3*2+n/2+1<<endl;
    }else if(n%6==1){
        cout<<n/3*2+n/2+2<<endl;
    }else if(n%3==1){
        cout<<n/3*2+n/2+1<<endl;
    }else if(n%6==2){
        cout<<n/3*2+n/2+2<<endl;
    }else if(n%6==5){
        cout<<n/3*2+n/2+2<<endl;
    }

    return 0;
}