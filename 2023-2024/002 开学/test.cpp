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

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main(){

    int i,j;
    cin>>i>>j;
    cout<<i<<"/"<<j<<"=";

    int g=gcd(i,j);
    i/=g,j/=g;

    while(i!=1){
        int k=ceil((double)j/(double)i);
        cout<<"1/"<<k<<"+";
        i=k*i-j;
        j=j*k;
        g=gcd(i,j);
        i/=g,j/=g;
    }
    cout<<"1/"<<j<<endl;

    return 0;
}