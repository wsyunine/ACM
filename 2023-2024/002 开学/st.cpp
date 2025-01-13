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
#define N 300010
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

// int n,m,f[N][20],log[N]={-1},a,b,ans[N];
// void work(int a[],int b[][2],int n,int m){
//     for(int i=1;i<=n;i++) f[i][0]=a[i],log[i]=log[i/2]+1;
//     for(int j=1;j<=log[n];j++){
// 		for(int i=1;i+(1<<i)-1<=n;i++){
// 			f[i][j]=max(f[i][j-1],f[i][j+(1<<(i-1))][i-1]);
//         }
//     }
    
//     for(int i=1;i<=m;i++){
// 		int len=log[b[i][1]-b[i][0]+1];
//         ans[i]=max(f[b[i][0]][len],f[b[i][1]-(1<<len)+1][len]);
//     }
    
// 	return 0;
// }

int n,m,f[30][N],lg[N]={-1},a[N];

void init(){
    for(int i=1;i<=n;i++) f[0][i]=a[i],lg[i]=lg[i/2]+1;
    for(int i=1;i<=lg[n];i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j+(1<<(i-1))]);
        }
    }
}

int query(int l,int r){
    int len=lg[r-l+1];
    return max(f[len][l],f[len][r-(1<<len)+1]);
}

int main(){

    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);

    init();

    for(int i=1;i<=m;i++){
        int a,b;
        read(a),read(b);
        printf("%d\n",query(a,b));
    }

    return 0;
}