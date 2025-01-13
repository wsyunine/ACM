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
int n,m;
int a[N],q[N],hd=-1,tl=0,ans=0;

int main(){

    read(t);
    while(t--){
        read(n),read(m);ans=0;hd=-1,tl=0;
        for(int i=1;i<=n;i++) read(a[i]);
        sort(a+1,a+1+n);

        for(int i=1;i<=n;i++){
            //cout<<a[i]<<endl;
            if(a[i]-a[i-1]>1){
                hd=tl-1;
                q[++hd]=a[i];
                ans=max(ans,hd-tl+1);
            }else{
                q[++hd]=a[i];
                while(hd>=tl&&q[hd]-q[tl]>=m) tl++;
                ans=max(ans,hd-tl+1);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}