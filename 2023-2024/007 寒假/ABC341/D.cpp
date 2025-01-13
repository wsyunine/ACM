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

int n,m,k;

int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}

signed main(){

    read(n),read(m),read(k);

    int g=gcd(n,m);

    int res=n/g+m/g-2;
    int nth=(k-1)/res,nt=(k-1)%res+1;

    int posi=1,posj=1;
    for(int i=1;i<=nt;i++){
        if(posi*n<posj*m&&posi<m/g) res=posi*n,posi++;
        else if(posj<n/g) res=posj*m,posj++;
    }

    cout<<res+n*m/g*nth<<endl;

    return 0;
}