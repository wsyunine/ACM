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

int fpow(int a,int b,int p){
    int res=1;a%=p;
    for(;b;b>>=1,a=a*a%p) if(b&1) (res*=a)%=p;
    return res%p;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

signed main(){

    int a,m;
    bool flg=0;
    string b;
    cin>>a>>m;
    cin>>b;
    int mm=m,phi=m;
    for(int i=2;i*i<=mm;i++){
        if(mm%i) continue;
        phi/=i;
        phi*=(i-1);
        while(mm%i==0){
            mm/=i;
        }
    }
    if(mm>1){
        phi/=mm;
        phi*=(mm-1);
    }

    int l=b.size(),bb=0;
    for(int i=0;i<l;i++){
        bb=bb*10+b[i]-'0';
        if(bb>=phi) flg=1,bb%=phi;
    }

    if(!flg){
        cout<<fpow(a,bb,m);
    }else{
        cout<<fpow(a,bb+phi,m);
    }
    cout<<endl;

    return 0;
}