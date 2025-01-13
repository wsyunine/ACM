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

int s,x;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(s),read(x);

    if(gcd(s,x)==1){
        cout<<1<<endl;
        cout<<s<<endl;
        return 0;
    }

    if(s%2&&(!(x%2))){
        int i;
        for(i=s-2;;i--){
            if(gcd(abs(i),x)==1&&gcd(abs(s-1-i),x)==1) break;
        }
        cout<<3<<endl;
        cout<<1<<" "<<i<<" "<<s-1-i<<endl;
    }else{
        int i;
        for(i=s-1;;i--){
            if(gcd(abs(i),x)==1&&gcd(abs(s-i),x)==1) break;
        }
        cout<<2<<endl;
        cout<<i<<" "<<s-i<<endl;
    }

    return 0;
}