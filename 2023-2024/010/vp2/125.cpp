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

int n;
int A,B,C,D;
int bt[N],b[N];
array<int,3> a[N];

int t[N];

int fpow(int a,int b){
    int p=149;
    int res=1;
    for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;
    return res;
}

void add(int x,int y){
    for(;x<=n;x+=x&(-x)) t[x]+=y;
}

int query(int x){
    int res=0;
    for(;x;x-=x&(-x)) res+=t[x];
    return res;
}

int main(){

    read(n);read(A),read(B),read(C),read(D);
    for(int i=1;i<=n;i++) read(a[i][0]);

    for(int i=1;i<=n;i++){
        int pos=a[i];
        while(pos){
            bt[i]+=(pos&1);
            pos>>=1;
        }
    }
    
    for(int i=1;i<=n;i++){
        b[i]=(fpow(A,i)+fpow(B,i)+fpow(C,i)+fpow(D,i));
        b[i]=(b[i]-74+149)%149;
    }

    for(int i=1;i<=n;i++) bt[i]=bt[i]*b[i];
    
    return 0;
}