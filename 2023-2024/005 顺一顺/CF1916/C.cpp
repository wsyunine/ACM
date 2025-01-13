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

int t;
int n,a[N],s[N],s1[N];

signed main(){

    read(t);
    while(t--){
        read(n);
        s[0]=0,s1[0]=0;
        for(int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]+a[i],s1[i]=s1[i-1]+a[i]%2;

        cout<<s[1]<<" ";
        for(int i=2;i<=n;i++){
            int sp=s1[i]%3,p;
            if(sp==1) p=1;
            else p=0;
            cout<<s[i]-p-s1[i]/3<<" ";
        }
        cout<<endl;
    }

    return 0;
}