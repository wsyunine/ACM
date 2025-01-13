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
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
double a[N];
double s[N],ans[N];
int stk[N],top=0;

double calc(int x1,int x2){
    return (double)abs(s[x1]-s[x2])/(double)abs(x1-x2);
}

int main(){

    read(n);
    for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i];

    stk[++top]=n;
    for(int i=n-1;i>=0;i--){
        while(top>1&&calc(stk[top],i)<calc(stk[top-1],i)) top--;
        ans[i+1]=calc(stk[top],i);
        stk[++top]=i;
    }

    for(int i=1;i<=n;i++) cout<<fixed<<setprecision(8)<<ans[i]<<endl;

    return 0;
}