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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
ll a,b;

int main(){

    read(n);
    while(n--){
        read(a),read(b);
        if(a*b<0) cout<<0<<endl;
        else{
            a=abs(a),b=abs(b);
            cout<<min(a,min(b,(ll)abs(a-b)))<<endl;
        }
    }

    return 0;
}