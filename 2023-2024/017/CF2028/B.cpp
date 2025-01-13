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
int b,c;

signed main(){

    read(t);
    while(t--){
        read(n);read(b),read(c);

        if(n==1){
            if(c==0) cout<<0<<endl;
            else cout<<1<<endl;
            continue;
        }else if(n==2){
            if(c==0&&b==1) cout<<0<<endl;
            else if(c==0) cout<<1<<endl;
            else if(c==1) cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }

        if(b==0){
            if(c<n-2) cout<<-1<<endl;
            else if(c<=n-1) cout<<n-1<<endl;
            else cout<<n<<endl;
            continue;
        }

        int l=1,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            if((mid-1)>=n-c||(mid-1)>=(n-c)/b+1||(mid-1)*b>=(n-c)) r=mid;
            else l=mid+1;
        }

        // if((n-1)*b+c<)

        cout<<n-l+1<<endl;

    }

    return 0;
}   