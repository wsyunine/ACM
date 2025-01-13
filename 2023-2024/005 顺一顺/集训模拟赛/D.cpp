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

int t;
int n,c;
int p[N];
short f[50010][510];

int main(){

    read(t);
    while(t--){
        read(n),read(c);
        memset(f,-1,sizeof f);
        for(int i=1;i<=n;i++) read(p[i]);
        sort(p+1,p+1+n);
        if(p[n]==c){
            cout<<0<<endl;
            continue;
        }
        
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++) f[i][j]=f[i-1][j];
            f[i][p[i]]=p[i];
            for(int j=p[i];j<=c;j++){
                f[i][j]=max(f[i][j],f[i-1][j-p[i]]);
            }
            if(f[i][c]!=-1) ans=min(ans,p[i]-f[i][c]);
        }

        if(ans==0x3f3f3f3f) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}