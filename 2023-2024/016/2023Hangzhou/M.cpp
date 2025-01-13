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
#define N 500010
#define ll long double
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
ll a[N];

int main(){

    read(t);
    while(t--){
        read(n);
        ll res1=0,res2=0,res3=0;
        ll sum1=0,sum2=0,sum3=n;
        int pos=0;
        a[0]=1e9+7;
        for(int i=1;i<=n;i++){
            read(a[i]);res3+=a[i];
            if(a[i]<a[i-1]) res1+=a[i];
            if(a[i]>a[i-1]&&pos==0) pos=i;
            if(a[i]>a[i-1]) res2+=a[i];
        }
        sum1=pos;
        sum2=n-pos+3;
        res1+=a[pos];
        res2+=a[pos-2]+a[pos-1];

        cout<<fixed<<setprecision(10)<<max(res1/sum1,max(res2/sum2,res3/sum3))<<endl;

    }


    return 0;
}