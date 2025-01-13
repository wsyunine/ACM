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
int a[N],b[N];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        int g=a[1];
        for(int i=1;i<=n;i++) g=gcd(g,a[i]);
        sort(a+1,a+1+n);

        int id=0,ss=0;
        for(int i=1;i<=n;i++) if(g%a[i]==0) id=1;
        if(id){
            cout<<n-1<<endl;
            continue;
        }

        for(int i=1;i<=n;i++){
            b[i]=(i==1)?a[2]:a[1];
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                b[i]=gcd(b[i],a[j]);
            }
        }

        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]%a[i]==0) continue;
                if(b[j]%(a[j]%a[i])==0) id=1;
            }
        }
        if(id){
            cout<<n<<endl;
            continue;
        }

        int s=0;
        for(int i=2;i<=n;i++){
            if(a[i]%a[1]==0) s++;
        }
        if(s==n-2){
            cout<<n<<endl;
            continue;
        }

        s=0;
        for(int i=3;i<=n;i++){
            if(a[i]%a[2]==0) s++;
        }
        if(s==n-2){
            cout<<n<<endl;
            continue;
        }

        int gg=a[2];
        for(int i=2;i<=n;i++) gg=gcd(gg,a[i]);
        if(a[1]<gg){
            cout<<n<<endl;
            continue;
        }

        cout<<n+1<<endl;
    }

    return 0;
}