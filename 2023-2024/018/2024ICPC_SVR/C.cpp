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
int t;
int a[N];
long long op[5],tp=0;

int main(){

    read(t);
    while(t--){
        read(n);tp=0;
        for(int i=1;i<=n;i++) read(a[i]);

        sort(a+1,a+1+n);
        int i=1;
        for(i=1;i<n;i++){
            if(a[i]==a[i+1]){
                op[++tp]=a[i];
                i++;
            }
            if(tp==2) break;
        }
        int j=n;
        for(j=n;j>i+1;j--){
            if(a[j]==a[j-1]){
                op[++tp]=a[j];
                j--;
            }
            if(tp==4) break;
        }

        if(tp==4){
            printf("YES\n");
            if((op[3]-op[1])*(op[4]-op[2])>(op[4]-op[1])*(op[3]-op[2])) printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",op[1],op[2],op[1],op[4],op[3],op[2],op[3],op[4]);
            else printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",op[1],op[2],op[1],op[3],op[4],op[2],op[4],op[3]);
        }else{
            printf("NO\n");
        }
    }

    return 0;
}