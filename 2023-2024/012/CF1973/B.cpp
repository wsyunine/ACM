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

int n;
int t;
int a[N],b[N][21];

bool check(int x){
    int op=0;
    bool ans=1;
    for(int i=x+1,j=2;i<=n;i++,j++){
        for(int k=0;k<20;k++){
            if(((b[i][k]-b[j-1][k])&&(b[i-1][k]-b[j-2][k]))||((!(b[i][k]-b[j-1][k]))&&(!(b[i-1][k]-b[j-2][k]))));
            else ans=0;
        }
    }
    return ans;
}

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);

        for(int i=1;i<=n;i++){
            for(int j=0;j<20;j++){
                if((a[i]>>j)&1) b[i][j]=1;
                else b[i][j]=0;
            }
        }
        for(int j=0;j<20;j++){
            for(int i=1;i<=n;i++){
                b[i][j]+=b[i-1][j];
            }
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<20;j++) cout<<b[i][j]<<" ";
        //     cout<<endl;
        // }

        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }

        cout<<l<<endl;
    }

    return 0;
}