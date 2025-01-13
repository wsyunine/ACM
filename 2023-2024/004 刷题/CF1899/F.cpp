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

int n,q;
int t;
int a[N];

int main(){

    read(t);
    while(t--){
        read(n);read(q);
        for(int i=1;i<=q;i++) read(a[i]);

        for(int i=1;i<n;i++) cout<<i<<" "<<i+1<<endl;
        int pos=n-1;
        for(int i=1;i<=q;i++){
            if(pos==a[i]) cout<<"-1 -1 -1"<<endl;
            else{cout<<n<<" "<<pos<<" "<<a[i]<<endl;pos=a[i];}
        }
    }


    return 0;
}