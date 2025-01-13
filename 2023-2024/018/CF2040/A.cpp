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

int n;
int t,k;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);read(k);
        int res=-1;
        for(int i=1;i<=n;i++) read(a[i]);

        for(int i=1;i<=n;i++){
            int idea=1;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(abs(a[i]-a[j])%k==0) idea=0;
            }
            if(idea) res=i;
        }

        if(res==-1) cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
            cout<<res<<endl;
        }
    }

    return 0;
}