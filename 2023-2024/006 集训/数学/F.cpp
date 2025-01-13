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

int t;
int n;
int a[N],ans=0x3f3f3f3f;

int main(){

    read(t);

    while(t--){
        ans=0x3f3f3f3f;
        read(n);

        for(int i=1;i<=n;i++) read(a[i]);

        if(n==1){cout<<0<<endl;continue;}

        for(int iii=1;iii<n;iii++){
            for(int ii=iii+1;ii<=n;ii++){
                double i=(double)(a[iii]-a[ii])/(double)(iii-ii);
                int j=iii;
                int d=0;
                for(int k=1;k<=n;k++){
                    if(j==k) d++;
                    else if((double)(a[j]-a[k])/(double)(j-k)==i) d++;
                }
                ans=min(ans,n-d);
            }
        }
        
        cout<<ans<<endl;
    }

    

    return 0;
}