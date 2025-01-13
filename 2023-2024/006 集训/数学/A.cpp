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

int n,p,m;
int A[501][501],B[501][501],C[501][501];
const int Mod=1e9+7;

signed main(){

    read(n),read(p),read(m);

    for(int i=1;i<=n;i++) for(int j=1;j<=p;j++) read(A[i][j]);
    for(int i=1;i<=p;i++) for(int j=1;j<=m;j++) read(B[i][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=p;k++){
                C[i][j]=(C[i][j]+(A[i][k]*B[k][j]%Mod+Mod)%Mod+Mod)%Mod;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}