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
#define N 100000010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n;
int notp[N];
int pri[N],cnt=0;

void prime(int n){
    notp[1]=1;
    for(int i=2;i<=n;i++){
        if(!notp[i]) pri[++cnt]=i;
        for(int j=1,t;j<=cnt&&(t=i*pri[j])<=n;j++){
            notp[t]=1;
            if(i%pri[j]==0) break;
        }
    }
}

int main(){

    int m;
    read(n),read(m);

    prime(n);

    for(int i=1;i<=m;i++){
        int a;
        read(a);
        cout<<pri[a]<<endl;
    }

    return 0;
}