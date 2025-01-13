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
#define N 200010
#define int long long
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t,n,ans=0;
int a[N];

int num1(int a,int b){
    int f=0,cnt=0;
    while(a!=0||b!=0){
        int x=a%10,y=b%10;
        f=(x+y+f)/10;
        cnt+=f;
        a/=10,b/=10;
    }
    return cnt;
}

signed main(){

    read(t);
    while(t--){
        read(n);
        int mx=0;ans=0;
        int num=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            ans+=num1(num,a[i]);
            num+=a[i];
        }
        cout<<ans<<endl;
    }

    

    return 0;
}