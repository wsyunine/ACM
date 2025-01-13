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
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}

signed main(){

    int a,b,cnt=0;
    cin>>a>>b;
    int c=a*b;
    for(int i=min(a,b);i*i<=c;i++){
        if(c%i==0&&gcd(i,c/i)==min(a,b)) cnt+=2;
        if(i*i==c&&c%i==0&&gcd(i,c/i)==min(a,b)) cnt--;
    }

    cout<<cnt<<endl;

    return 0;
}