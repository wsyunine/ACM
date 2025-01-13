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
int a,b,c;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(t);
    while(t--){
        read(a),read(b),read(c);
        while(a%2==0&&b%2==0&&c%2==0) a/=2,b/=2,c/=2;
        
        if(a%2==1&&b%2==1&&c%2==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}