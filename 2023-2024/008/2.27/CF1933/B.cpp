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

int t,n,a[N],sum=0;

int main(){

    read(t);
    while(t--){
        int idea1=2,idea2=2;sum=0;
        read(n);
        for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
        for(int i=1;i<=n;i++){
            if((sum-a[i])%3==0) idea1=1;
        }
        idea2=sum%3;
        if(idea2==2) idea2=1;
        else if(idea2==1) idea2=2;
        cout<<min(idea2,idea1)<<endl;
    }

    return 0;
}