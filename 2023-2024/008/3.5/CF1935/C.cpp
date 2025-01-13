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
#define ll long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int n,l;
int t;
pair<int,int> a[N];
ll f[2010][2010];
ll minn[2010];
int ans=0;

int main(){

    read(t);
    while(t--){
        read(n);read(l);ans=0;

        for(int i=1;i<=n;i++){
            read(a[i].second);read(a[i].first);
        }   

        sort(a+1,a+1+n);

        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++) f[i][1]=a[i].second;
        for(int i=1;i<=n;i++) minn[i]=0x3f3f3f3f3f3f3f3f;
        minn[1]=f[1][1];
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1;j--){
                if(j!=1){
                    f[i][j]=min(f[i][j],minn[j-1]+(ll)a[i].first+(ll)a[i].second);
                    // cout<<minn[j-1]<<" ";
                }
                minn[j]=min(minn[j],f[i][j]-(ll)a[i].first);
                if(f[i][j]<=l) ans=max(ans,j);
            }
            // cout<<endl;
        }

        cout<<ans<<endl;
    }   

    return 0;
}