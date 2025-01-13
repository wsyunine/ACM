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
#define int long long 
template<typename T>
inline void read(T &x){
    x=0;bool flg=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') flg=1;
    for(;isdigit(c);c=getchar()) x=x*10+(c^48);
    if(flg) x=-x;
}

int t;
int n;
int a[N];

signed main(){

    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        int idea=1;

        int tmp=0,sum=0;
        for(int i=1;i<=n;i+=2){
            sum++;
            tmp+=a[i];
        }
        if(tmp%sum!=0) idea=0;
        int sop=tmp/sum;

        tmp=0,sum=0;
        for(int i=2;i<=n;i+=2){
            sum++;
            tmp+=a[i];
        } 
        if((tmp%sum!=0)||(tmp/sum!=sop)) idea=0;

        if(idea) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}