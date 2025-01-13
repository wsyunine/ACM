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
int a[N],mingcd=0x3f3f3f3f3f3f3f3f,minc=0;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        vector<int> ip(5010,0);

        int id=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((j%i==0)!=(a[j]%a[i]==0)) id=0;
            }
        }

        if(id==0){cout<<"No"<<endl;continue;}

        for(int p=2;p<=n;p++){
            if(ip[p]) continue;
            for(int i=2;n/p>=i;i++) ip[p*i]=1;
            int k=1;
            for(int i=p;i<=n/p;i*=p) k++;
            vector<int> mn(k+1,0x3f3f3f3f3f3f3f3f),mx(k+1,-0x3f3f3f3f3f3f3f3f);
            for(int i=1;i<=n;i++){
                int c=0;
                for(int x=i;x%p==0;x/=p) ++c;
                int d=0;
                for(int x=a[i];x%p==0;x/=p) ++d;
                mn[c]=min(mn[c],d);
                mx[c]=max(mx[c],d);
            }
            for(int i=1;i<=k;i++){
                if(mx[i-1]>=mn[i]) id=0;
            }
        } 

        if(id) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

    return 0;
}